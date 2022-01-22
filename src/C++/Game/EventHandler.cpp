#include "Game/EventHandler.h"
#include "Serialization/EventHolder.h"

namespace Event
{
	EventResult ScriptEventHandler::ProcessEvent(const RE::TESCellFullyLoadedEvent* a_event, RE::BSTEventSource<RE::TESCellFullyLoadedEvent>*)
	{
		if (!a_event || !a_event->cell) {
			return EventResult::kContinue;
		}

		ScriptEventHolder::GetSingleton()->cellFullyLoaded.QueueEvent(a_event->cell);

		return EventResult::kContinue;
	}

	EventResult ScriptEventHandler::ProcessEvent(const RE::TESQuestStartStopEvent* a_event, RE::BSTEventSource<RE::TESQuestStartStopEvent>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		if (const auto quest = RE::TESForm::LookupByID<RE::TESQuest>(a_event->formID); quest) {
			auto& event = a_event->started ? ScriptEventHolder::GetSingleton()->questStart : ScriptEventHolder::GetSingleton()->questStop;
			event.QueueEvent(a_event->formID, quest);
		}

		return EventResult::kContinue;
	}

	EventResult ScriptEventHandler::ProcessEvent(const RE::TESQuestStageEvent* a_event, RE::BSTEventSource<RE::TESQuestStageEvent>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		if (const auto quest = RE::TESForm::LookupByID<RE::TESQuest>(a_event->formID); quest) {
			ScriptEventHolder::GetSingleton()->questStage.QueueEvent(a_event->formID, quest, a_event->stage);
		}

		return EventResult::kContinue;
	}

	EventResult ScriptEventHandler::ProcessEvent(const RE::TESObjectLoadedEvent* a_event, RE::BSTEventSource<RE::TESObjectLoadedEvent>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		const auto object = RE::TESForm::LookupByID<RE::TESObjectREFR>(a_event->formID);
		const auto base = object ? object->GetBaseObject() : nullptr;

		if (base) {
			auto baseType = base->GetFormType();
			auto& event = a_event->loaded ? ScriptEventHolder::GetSingleton()->objectLoaded : ScriptEventHolder::GetSingleton()->objectUnloaded;

			event.QueueEvent(baseType, object, baseType);
		}

		return EventResult::kContinue;
	}

	EventResult ScriptEventHandler::ProcessEvent(const RE::TESGrabReleaseEvent* a_event, RE::BSTEventSource<RE::TESGrabReleaseEvent>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		if (const auto object = a_event->ref; object) {
			auto& event = a_event->grabbed ? ScriptEventHolder::GetSingleton()->objectGrab : ScriptEventHolder::GetSingleton()->objectRelease;
			event.QueueEvent(object.get());
		}

		return EventResult::kContinue;
	}

}

namespace Event
{
	EventResult StoryEventHandler::ProcessEvent(const RE::ActorKill::Event* a_event, RE::BSTEventSource<RE::ActorKill::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		const auto victim = a_event->victim;
		const auto killer = a_event->killer;

		if (victim) {
			StoryEventHolder::GetSingleton()->actorKill.QueueEvent(victim, killer);
		}

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::BooksRead::Event* a_event, RE::BSTEventSource<RE::BooksRead::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		if (const auto book = a_event->book; book) {
			StoryEventHolder::GetSingleton()->booksRead.QueueEvent(book);
		}

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::CriticalHit::Event* a_event, RE::BSTEventSource<RE::CriticalHit::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		const auto agressor = a_event->aggressor;
		const auto agressorActor = agressor ? agressor->As<RE::Actor>() : nullptr;

		const auto weapon = a_event->weapon;

		if (agressorActor && weapon) {
			StoryEventHolder::GetSingleton()->criticalHit.QueueEvent(agressorActor, weapon, a_event->sneakHit);
		}

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::DisarmedEvent::Event* a_event, RE::BSTEventSource<RE::DisarmedEvent::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		const auto source = a_event->source;
		const auto target = a_event->target;

		if (source && target) {
			StoryEventHolder::GetSingleton()->disarmed.QueueEvent(source, target);
		}

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::DragonSoulsGained::Event* a_event, RE::BSTEventSource<RE::DragonSoulsGained::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		StoryEventHolder::GetSingleton()->dragonSoulsGained.QueueEvent(a_event->souls);

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::TESHarvestedEvent::ItemHarvested* a_event, RE::BSTEventSource<RE::TESHarvestedEvent::ItemHarvested>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		if (const auto produce = a_event->produceItem; produce) {
			StoryEventHolder::GetSingleton()->itemHarvested.QueueEvent(produce);
		}

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::LevelIncrease::Event* a_event, RE::BSTEventSource<RE::LevelIncrease::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		StoryEventHolder::GetSingleton()->levelIncrease.QueueEvent(a_event->newLevel);

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::LocationDiscovery::Event* a_event, RE::BSTEventSource<RE::LocationDiscovery::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		if (const auto data = a_event->mapMarkerData; data) {
			StoryEventHolder::GetSingleton()->locationDiscovery.QueueEvent(data->locationName.fullName, a_event->worldspaceID);
		}

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::ShoutAttack::Event* a_event, RE::BSTEventSource<RE::ShoutAttack::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		if (const auto shout = a_event->shout; shout) {
			StoryEventHolder::GetSingleton()->shoutAttack.QueueEvent(shout);
		}

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::SkillIncrease::Event* a_event, RE::BSTEventSource<RE::SkillIncrease::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		StoryEventHolder::GetSingleton()->skillIncrease.QueueEvent(::stl::to_underlying(a_event->actorValue));

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::SoulsTrapped::Event* a_event, RE::BSTEventSource<RE::SoulsTrapped::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		const auto trapper = a_event->trapper;
		const auto target = a_event->target;

		if (trapper && target) {
			StoryEventHolder::GetSingleton()->soulsTrapped.QueueEvent(target, trapper);
		}

		return EventResult::kContinue;
	}

	EventResult StoryEventHandler::ProcessEvent(const RE::SpellsLearned::Event* a_event, RE::BSTEventSource<RE::SpellsLearned::Event>*)
	{
		if (!a_event) {
			return EventResult::kContinue;
		}

		if (const auto spell = a_event->spell; spell) {
			StoryEventHolder::GetSingleton()->spellsLearned.QueueEvent(spell);
		}

		return EventResult::kContinue;
	}
}

namespace Event::GameEventHandler
{
	namespace FallLongDistance
	{
		struct CalcDoDamage
		{
			static float thunk(RE::Actor* a_this, float a_fallDistance, float a_defaultMult)
			{
				auto fallDamage = func(a_this, a_fallDistance, a_defaultMult);
				if (fallDamage > 0.0f) {
					GameEventHolder::GetSingleton()->actorFallLongDistance.QueueEvent(a_this, a_this, a_fallDistance, fallDamage);
				}
				return fallDamage;
			}
			static inline REL::Relocation<decltype(&thunk)> func;
		};

		inline void Install()
		{
			REL::Relocation<std::uintptr_t> take_ragdoll_damage{ REL::ID(36346) };
			::stl::write_thunk_call<CalcDoDamage>(take_ragdoll_damage.address() + 0x35);

			REL::Relocation<std::uintptr_t> process_movefinish_event{ REL::ID(36973) };
			::stl::write_thunk_call<CalcDoDamage>(process_movefinish_event.address() + 0xAE);

			logger::info("Hooked Fall Damage"sv);
		}
	}

	namespace Resurrect
	{
		struct Resurrect
		{
			static void thunk(RE::Character* a_this, bool a_resetInventory, bool a_attach3D)
			{
				func(a_this, a_resetInventory, a_attach3D);

				GameEventHolder::GetSingleton()->actorResurrect.QueueEvent(a_this, a_this, a_resetInventory);
			}
			static inline REL::Relocation<decltype(&thunk)> func;
		};

		void Install()
		{
			::stl::write_vfunc<RE::Character,
#ifndef SKYRIMVR
				0x0AB
#else
				0x0AD
#endif
				,
				Resurrect>();

			logger::info("Hooked Actor Resurrect"sv);
		}
	}

	namespace Reanimate
	{
		struct Start
		{
			static void thunk(RE::ReanimateEffect* a_this)
			{
				func(a_this);

				if (a_this->flags.none(RE::ActiveEffect::Flag::kDispelled)) {  //effect can get dispelled in original func

					const auto zombiePtr = a_this->commandedActor.get();
					const auto zombie = zombiePtr.get();
					if (!zombie) {
						return;
					}

					if (zombie->boolBits.all(RE::Actor::BOOL_BITS::kParalyzed)) {
						const auto root = zombie->Get3D(false);
						const auto charController = zombie->GetCharController();
						if (root && charController) {
							zombie->boolBits.reset(RE::Actor::BOOL_BITS::kParalyzed);

							root->UpdateRigidConstraints(false);

							std::uint32_t filterInfo = 0;
							charController->GetCollisionFilterInfo(filterInfo);

							root->SetCollisionLayerAndGroup(RE::COL_LAYER::kDeadBip, filterInfo >> 16);
						}
					}

					const auto caster = a_this->caster.get();
					if (caster) {
						GameEventHolder::GetSingleton()->actorReanimateStart.QueueEvent(zombie, zombie, caster.get());
					}
				}
			}
			static inline REL::Relocation<decltype(&thunk)> func;
		};

		struct Stop
		{
			static void thunk(RE::ReanimateEffect* a_this)
			{
				const auto zombiePtr = a_this->commandedActor.get();
				const auto caster = a_this->caster.get();
				if (zombiePtr && caster) {
					const auto zombie = zombiePtr.get();
					GameEventHolder::GetSingleton()->actorReanimateStop.QueueEvent(zombie, zombie, caster.get());
				}

				func(a_this);
			}
			static inline REL::Relocation<decltype(&thunk)> func;
		};

		void Install()
		{
			::stl::write_vfunc<RE::ReanimateEffect, 0x14, Start>();
			::stl::write_vfunc<RE::ReanimateEffect, 0x15, Stop>();

			logger::info("Hooked Actor Reanimate Start"sv);
			logger::info("Hooked Actor Reanimate Stop"sv);
		}
	};

	namespace MagicEffectApply
	{
		struct MagicTargetApply
		{
			static bool thunk(RE::MagicTarget* a_this, RE::MagicTarget::CreationData* a_data)
			{
				auto result = func(a_this, a_data);

				const auto target = a_this ? a_this->GetTargetStatsObject() : nullptr;
				if (target && a_data) {
					const auto effect = a_data->effect;
					const auto baseEffect = effect ? effect->baseEffect : nullptr;
					if (baseEffect) {
						GameEventHolder::GetSingleton()->magicApply.QueueEvent(target, baseEffect, a_data->caster, baseEffect, a_data->magicItem, result);
					}
				}

				return result;
			}
			static inline REL::Relocation<decltype(thunk)> func;
		};

		static void Install()
		{
			REL::Relocation<std::uintptr_t> target{ REL::ID(33742), 0x1E8 };
			::stl::write_thunk_call<MagicTargetApply>(target.address());

			logger::info("Hooked Magic Effect Apply"sv);
		}
	}

	namespace MagicHit
	{
		struct SendHitEvent
		{
			static void thunk(RE::BSTEventSource<RE::TESHitEvent>& a_source, RE::TESHitEvent& a_event)
			{
				if (const auto aggressor = a_event.cause.get(); aggressor) {
					const auto target = a_event.target.get();
					const auto source = RE::TESForm::LookupByID(a_event.source);
					const auto projectile = RE::TESForm::LookupByID<RE::BGSProjectile>(a_event.projectile);

					GameEventHolder::GetSingleton()->magicHit.QueueEvent(aggressor, target, source, projectile);
				}

				func(a_source, a_event);
			}
			static inline REL::Relocation<decltype(&thunk)> func;
		};

		void Install()
		{
			REL::Relocation<std::uintptr_t> target{ REL::ID(37832), 0x1C3 };
			::stl::write_thunk_call<SendHitEvent>(target.address());

			logger::info("Hooked Magic Hit"sv);
		}
	}

	namespace WeaponHit
	{
		namespace Actor
		{
			REL::Relocation<std::uintptr_t> target{ REL::ID(37633), 0x16A };

			struct SendHitEvent
			{
				static void thunk(RE::ScriptEventSourceHolder* a_holder,
					RE::NiPointer<RE::TESObjectREFR>& a_target,
					RE::NiPointer<RE::TESObjectREFR>& a_aggressor,
					RE::FormID a_source,
					RE::FormID a_projectile,
					RE::HitData& a_data)
				{
					if (const auto aggressor = a_aggressor.get(); aggressor) {
						const auto hitTarget = a_target.get();
						const auto source = RE::TESForm::LookupByID(a_source);
						const auto flags = ::stl::to_underlying(a_data.flags);

						GameEventHolder::GetSingleton()->weaponHit.QueueEvent(aggressor, hitTarget, source, nullptr, flags);
					}

					func(a_holder, a_target, a_aggressor, a_source, a_projectile, a_data);
				}
				static inline REL::Relocation<decltype(thunk)> func;
			};
		}

		namespace Static
		{
			REL::Relocation<std::uintptr_t> target{ REL::ID(37674), 0x6C7 };

			struct SendHitEvent
			{
				static void thunk(RE::BSTEventSource<RE::TESHitEvent>& a_source, RE::TESHitEvent& a_event)
				{
					if (const auto aggressor = a_event.cause.get(); aggressor) {
						const auto hitTarget = a_event.target.get();
						const auto source = RE::TESForm::LookupByID(a_event.source);
						GameEventHolder::GetSingleton()->weaponHit.QueueEvent(aggressor, hitTarget, source, nullptr, 0);
					}
					func(a_source, a_event);
				}
				static inline REL::Relocation<decltype(thunk)> func;
			};
		}

		namespace Projectile
		{
			REL::Relocation<std::uintptr_t> target{ REL::ID(43022), 0x38D };

			struct SendHitEvent
			{
				static void thunk(RE::BSTEventSource<RE::TESHitEvent>& a_source, RE::TESHitEvent& a_event)
				{
					if (const auto aggressor = a_event.cause.get(); aggressor) {
						const auto hitTarget = a_event.target.get();
						const auto source = RE::TESForm::LookupByID(a_event.source);
						const auto projectile = RE::TESForm::LookupByID<RE::BGSProjectile>(a_event.projectile);

						if (projectile && projectile->data.types.all(RE::BGSProjectileData::Type::kArrow)) {
							GameEventHolder::GetSingleton()->weaponHit.QueueEvent(aggressor, hitTarget, source, projectile, 0);
						}
						GameEventHolder::GetSingleton()->projectileHit.QueueEvent(aggressor, hitTarget, source, projectile);
					}
					func(a_source, a_event);
				}
				static inline REL::Relocation<decltype(thunk)> func;
			};
		}

		inline void Install()
		{
			::stl::write_thunk_call<Actor::SendHitEvent>(Actor::target.address());
			::stl::write_thunk_call<Static::SendHitEvent>(Static::target.address());
			::stl::write_thunk_call<Projectile::SendHitEvent>(Projectile::target.address());

			logger::info("Hooked Weapon Hit"sv);
		}
	}

	//got rid of asm hook, the fact that it worked in SE without issues was a miracle
	namespace Weather
	{
		struct SetCurrentWeather
		{
			static void thunk(RE::TESRegion* a_region, RE::TESWeather* a_currentWeather)
			{
				if (currentWeather != a_currentWeather) {
					currentWeather = a_currentWeather;

					const auto sky = RE::Sky::GetSingleton();
					const auto lastWeather = sky ? sky->lastWeather : nullptr;

					GameEventHolder::GetSingleton()->weatherChange.QueueEvent(lastWeather, currentWeather);
				}

				func(a_region, a_currentWeather);
			}
			static inline REL::Relocation<decltype(&thunk)> func;

		private:
			static inline RE::TESWeather* currentWeather;
		};

		void Install()
		{
			REL::Relocation<std::uintptr_t> target{ REL::ID(25684) };
			::stl::write_thunk_call<SetCurrentWeather>(target.address() + 0x44F);

			logger::info("Hooked Weather Change"sv);
		}
	}

	void Register()
	{
		logger::info("{:*^30}", "HOOKED EVENTS"sv);

		FallLongDistance::Install();
		Resurrect::Install();
		Reanimate::Install();
		MagicEffectApply::Install();
		WeaponHit::Install();
		MagicHit::Install();
		Weather::Install();
	}
}

void Event::Register()
{
	ScriptEventHandler::Register();
	StoryEventHandler::Register();
	GameEventHandler::Register();
}
