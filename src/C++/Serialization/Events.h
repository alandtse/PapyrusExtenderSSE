#pragma once

namespace Events
{
	namespace Script
	{
		class OnCellFullyLoadedRegSet : public SKSE::RegistrationSet<const RE::TESObjectCELL*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::TESObjectCELL*>;

			static OnCellFullyLoadedRegSet* GetSingleton()
			{
				static OnCellFullyLoadedRegSet singleton;
				return &singleton;
			}

		private:
			OnCellFullyLoadedRegSet();
			OnCellFullyLoadedRegSet(const OnCellFullyLoadedRegSet&) = delete;
			OnCellFullyLoadedRegSet(OnCellFullyLoadedRegSet&&) = delete;
			~OnCellFullyLoadedRegSet() = default;

			OnCellFullyLoadedRegSet& operator=(const OnCellFullyLoadedRegSet&) = delete;
			OnCellFullyLoadedRegSet& operator=(OnCellFullyLoadedRegSet&&) = delete;
		};

		class OnQuestStartRegMap : public SKSE::RegistrationMap<const RE::TESQuest*>
		{
		public:
			using Base = SKSE::RegistrationMap<const RE::TESQuest*>;

			static OnQuestStartRegMap* GetSingleton()
			{
				static OnQuestStartRegMap singleton;
				return &singleton;
			}

		private:
			OnQuestStartRegMap();
			OnQuestStartRegMap(const OnQuestStartRegMap&) = delete;
			OnQuestStartRegMap(OnQuestStartRegMap&&) = delete;
			~OnQuestStartRegMap() = default;

			OnQuestStartRegMap& operator=(const OnQuestStartRegMap&) = delete;
			OnQuestStartRegMap& operator=(OnQuestStartRegMap&&) = delete;
		};

		class OnQuestStopRegMap : public SKSE::RegistrationMap<const RE::TESQuest*>
		{
		public:
			using Base = SKSE::RegistrationMap<const RE::TESQuest*>;

			static OnQuestStopRegMap* GetSingleton()
			{
				static OnQuestStopRegMap singleton;
				return &singleton;
			}

		private:
			OnQuestStopRegMap();
			OnQuestStopRegMap(const OnQuestStopRegMap&) = delete;
			OnQuestStopRegMap(OnQuestStopRegMap&&) = delete;
			~OnQuestStopRegMap() = default;

			OnQuestStopRegMap& operator=(const OnQuestStopRegMap&) = delete;
			OnQuestStopRegMap& operator=(OnQuestStopRegMap&&) = delete;
		};

		class OnQuestStageRegMap : public SKSE::RegistrationMap<const RE::TESQuest*, std::uint32_t>
		{
		public:
			using Base = SKSE::RegistrationMap<const RE::TESQuest*, std::uint32_t>;

			static OnQuestStageRegMap* GetSingleton()
			{
				static OnQuestStageRegMap singleton;
				return &singleton;
			}

		private:
			OnQuestStageRegMap();
			OnQuestStageRegMap(const OnQuestStageRegMap&) = delete;
			OnQuestStageRegMap(OnQuestStageRegMap&&) = delete;
			~OnQuestStageRegMap() = default;

			OnQuestStageRegMap& operator=(const OnQuestStageRegMap&) = delete;
			OnQuestStageRegMap& operator=(OnQuestStageRegMap&&) = delete;
		};

		class OnObjectLoadedRegMap : public SKSE::RegistrationMap<const RE::TESObjectREFR*, RE::FormType>
		{
		public:
			using Base = SKSE::RegistrationMap<const RE::TESObjectREFR*, RE::FormType>;

			static OnObjectLoadedRegMap* GetSingleton()
			{
				static OnObjectLoadedRegMap singleton;
				return &singleton;
			}

		private:
			OnObjectLoadedRegMap();
			OnObjectLoadedRegMap(const OnObjectLoadedRegMap&) = delete;
			OnObjectLoadedRegMap(OnObjectLoadedRegMap&&) = delete;
			~OnObjectLoadedRegMap() = default;

			OnObjectLoadedRegMap& operator=(const OnObjectLoadedRegMap&) = delete;
			OnObjectLoadedRegMap& operator=(OnObjectLoadedRegMap&&) = delete;
		};

		class OnObjectUnloadedRegMap : public SKSE::RegistrationMap<const RE::TESObjectREFR*, RE::FormType>
		{
		public:
			using Base = SKSE::RegistrationMap<const RE::TESObjectREFR*, RE::FormType>;

			static OnObjectUnloadedRegMap* GetSingleton()
			{
				static OnObjectUnloadedRegMap singleton;
				return &singleton;
			}

		private:
			OnObjectUnloadedRegMap();
			OnObjectUnloadedRegMap(const OnObjectUnloadedRegMap&) = delete;
			OnObjectUnloadedRegMap(OnObjectUnloadedRegMap&&) = delete;
			~OnObjectUnloadedRegMap() = default;

			OnObjectUnloadedRegMap& operator=(const OnObjectUnloadedRegMap&) = delete;
			OnObjectUnloadedRegMap& operator=(OnObjectUnloadedRegMap&&) = delete;
		};

		class OnGrabRegSet : public SKSE::RegistrationSet<const RE::TESObjectREFR*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::TESObjectREFR*>;

			static OnGrabRegSet* GetSingleton()
			{
				static OnGrabRegSet singleton;
				return &singleton;
			}

		private:
			OnGrabRegSet();
			OnGrabRegSet(const OnGrabRegSet&) = delete;
			OnGrabRegSet(OnGrabRegSet&&) = delete;
			~OnGrabRegSet() = default;

			OnGrabRegSet& operator=(const OnGrabRegSet&) = delete;
			OnGrabRegSet& operator=(OnGrabRegSet&&) = delete;
		};

		class OnReleaseRegSet : public SKSE::RegistrationSet<const RE::TESObjectREFR*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::TESObjectREFR*>;

			static OnReleaseRegSet* GetSingleton()
			{
				static OnReleaseRegSet singleton;
				return &singleton;
			}

		private:
			OnReleaseRegSet();
			OnReleaseRegSet(const OnReleaseRegSet&) = delete;
			OnReleaseRegSet(OnReleaseRegSet&&) = delete;
			~OnReleaseRegSet() = default;

			OnReleaseRegSet& operator=(const OnReleaseRegSet&) = delete;
			OnReleaseRegSet& operator=(OnReleaseRegSet&&) = delete;
		};
	}

	namespace Story
	{
		class OnActorKillRegSet : public SKSE::RegistrationSet<const RE::Actor*, const RE::Actor*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::Actor*, const RE::Actor*>;

			static OnActorKillRegSet* GetSingleton()
			{
				static OnActorKillRegSet singleton;
				return &singleton;
			}

		private:
			OnActorKillRegSet();
			OnActorKillRegSet(const OnActorKillRegSet&) = delete;
			OnActorKillRegSet(OnActorKillRegSet&&) = delete;
			~OnActorKillRegSet() = default;

			OnActorKillRegSet& operator=(const OnActorKillRegSet&) = delete;
			OnActorKillRegSet& operator=(OnActorKillRegSet&&) = delete;
		};

		class OnBooksReadRegSet : public SKSE::RegistrationSet<const RE::TESObjectBOOK*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::TESObjectBOOK*>;

			static OnBooksReadRegSet* GetSingleton()
			{
				static OnBooksReadRegSet singleton;
				return &singleton;
			}

		private:
			OnBooksReadRegSet();
			OnBooksReadRegSet(const OnBooksReadRegSet&) = delete;
			OnBooksReadRegSet(OnBooksReadRegSet&&) = delete;
			~OnBooksReadRegSet() = default;

			OnBooksReadRegSet& operator=(const OnBooksReadRegSet&) = delete;
			OnBooksReadRegSet& operator=(OnBooksReadRegSet&&) = delete;
		};

		class OnCriticalHitRegSet : public SKSE::RegistrationSet<const RE::Actor*, const RE::TESObjectWEAP*, bool>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::Actor*, const RE::TESObjectWEAP*, bool>;

			static OnCriticalHitRegSet* GetSingleton()
			{
				static OnCriticalHitRegSet singleton;
				return &singleton;
			}

		private:
			OnCriticalHitRegSet();
			OnCriticalHitRegSet(const OnCriticalHitRegSet&) = delete;
			OnCriticalHitRegSet(OnCriticalHitRegSet&&) = delete;
			~OnCriticalHitRegSet() = default;

			OnCriticalHitRegSet& operator=(const OnCriticalHitRegSet&) = delete;
			OnCriticalHitRegSet& operator=(OnCriticalHitRegSet&&) = delete;
		};

		class OnDisarmedRegSet : public SKSE::RegistrationSet<const RE::Actor*, const RE::Actor*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::Actor*, const RE::Actor*>;

			static OnDisarmedRegSet* GetSingleton()
			{
				static OnDisarmedRegSet singleton;
				return &singleton;
			}

		private:
			OnDisarmedRegSet();
			OnDisarmedRegSet(const OnDisarmedRegSet&) = delete;
			OnDisarmedRegSet(OnDisarmedRegSet&&) = delete;
			~OnDisarmedRegSet() = default;

			OnDisarmedRegSet& operator=(const OnDisarmedRegSet&) = delete;
			OnDisarmedRegSet& operator=(OnDisarmedRegSet&&) = delete;
		};

		class OnDragonSoulsGainedRegSet : public SKSE::RegistrationSet<float>
		{
		public:
			using Base = SKSE::RegistrationSet<float>;

			static OnDragonSoulsGainedRegSet* GetSingleton()
			{
				static OnDragonSoulsGainedRegSet singleton;
				return &singleton;
			}

		private:
			OnDragonSoulsGainedRegSet();
			OnDragonSoulsGainedRegSet(const OnDragonSoulsGainedRegSet&) = delete;
			OnDragonSoulsGainedRegSet(OnDragonSoulsGainedRegSet&&) = delete;
			~OnDragonSoulsGainedRegSet() = default;

			OnDragonSoulsGainedRegSet& operator=(const OnDragonSoulsGainedRegSet&) = delete;
			OnDragonSoulsGainedRegSet& operator=(OnDragonSoulsGainedRegSet&&) = delete;
		};

		class OnItemHarvestedRegSet : public SKSE::RegistrationSet<const RE::TESForm*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::TESForm*>;

			static OnItemHarvestedRegSet* GetSingleton()
			{
				static OnItemHarvestedRegSet singleton;
				return &singleton;
			}

		private:
			OnItemHarvestedRegSet();
			OnItemHarvestedRegSet(const OnItemHarvestedRegSet&) = delete;
			OnItemHarvestedRegSet(OnItemHarvestedRegSet&&) = delete;
			~OnItemHarvestedRegSet() = default;

			OnItemHarvestedRegSet& operator=(const OnItemHarvestedRegSet&) = delete;
			OnItemHarvestedRegSet& operator=(OnItemHarvestedRegSet&&) = delete;
		};

		class OnLevelIncreaseRegSet : public SKSE::RegistrationSet<std::uint32_t>
		{
		public:
			using Base = SKSE::RegistrationSet<std::uint32_t>;

			static OnLevelIncreaseRegSet* GetSingleton()
			{
				static OnLevelIncreaseRegSet singleton;
				return &singleton;
			}

		private:
			OnLevelIncreaseRegSet();
			OnLevelIncreaseRegSet(const OnLevelIncreaseRegSet&) = delete;
			OnLevelIncreaseRegSet(OnLevelIncreaseRegSet&&) = delete;
			~OnLevelIncreaseRegSet() = default;

			OnLevelIncreaseRegSet& operator=(const OnLevelIncreaseRegSet&) = delete;
			OnLevelIncreaseRegSet& operator=(OnLevelIncreaseRegSet&&) = delete;
		};

		class OnLocationDiscoveryRegSet : public SKSE::RegistrationSet<RE::BSFixedString, RE::BSFixedString>
		{
		public:
			using Base = SKSE::RegistrationSet<RE::BSFixedString, RE::BSFixedString>;

			static OnLocationDiscoveryRegSet* GetSingleton()
			{
				static OnLocationDiscoveryRegSet singleton;
				return &singleton;
			}

		private:
			OnLocationDiscoveryRegSet();
			OnLocationDiscoveryRegSet(const OnLocationDiscoveryRegSet&) = delete;
			OnLocationDiscoveryRegSet(OnLocationDiscoveryRegSet&&) = delete;
			~OnLocationDiscoveryRegSet() = default;

			OnLocationDiscoveryRegSet& operator=(const OnLocationDiscoveryRegSet&) = delete;
			OnLocationDiscoveryRegSet& operator=(OnLocationDiscoveryRegSet&&) = delete;
		};

		class OnShoutAttackRegSet : public SKSE::RegistrationSet<const RE::TESShout*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::TESShout*>;

			static OnShoutAttackRegSet* GetSingleton()
			{
				static OnShoutAttackRegSet singleton;
				return &singleton;
			}

		private:
			OnShoutAttackRegSet();
			OnShoutAttackRegSet(const OnShoutAttackRegSet&) = delete;
			OnShoutAttackRegSet(OnShoutAttackRegSet&&) = delete;
			~OnShoutAttackRegSet() = default;

			OnShoutAttackRegSet& operator=(const OnShoutAttackRegSet&) = delete;
			OnShoutAttackRegSet& operator=(OnShoutAttackRegSet&&) = delete;
		};

		class OnSkillIncreaseRegSet : public SKSE::RegistrationSet<RE::BSFixedString>
		{
		public:
			using Base = SKSE::RegistrationSet<RE::BSFixedString>;

			static OnSkillIncreaseRegSet* GetSingleton()
			{
				static OnSkillIncreaseRegSet singleton;
				return &singleton;
			}

		private:
			OnSkillIncreaseRegSet();
			OnSkillIncreaseRegSet(const OnSkillIncreaseRegSet&) = delete;
			OnSkillIncreaseRegSet(OnSkillIncreaseRegSet&&) = delete;
			~OnSkillIncreaseRegSet() = default;

			OnSkillIncreaseRegSet& operator=(const OnSkillIncreaseRegSet&) = delete;
			OnSkillIncreaseRegSet& operator=(OnSkillIncreaseRegSet&&) = delete;
		};

		class OnSoulsTrappedRegSet : public SKSE::RegistrationSet<const RE::Actor*, const RE::Actor*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::Actor*, const RE::Actor*>;

			static OnSoulsTrappedRegSet* GetSingleton()
			{
				static OnSoulsTrappedRegSet singleton;
				return &singleton;
			}

		private:
			OnSoulsTrappedRegSet();
			OnSoulsTrappedRegSet(const OnSoulsTrappedRegSet&) = delete;
			OnSoulsTrappedRegSet(OnSoulsTrappedRegSet&&) = delete;
			~OnSoulsTrappedRegSet() = default;

			OnSoulsTrappedRegSet& operator=(const OnSoulsTrappedRegSet&) = delete;
			OnSoulsTrappedRegSet& operator=(OnSoulsTrappedRegSet&&) = delete;
		};

		class OnSpellsLearnedRegSet : public SKSE::RegistrationSet<const RE::SpellItem*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::SpellItem*>;

			static OnSpellsLearnedRegSet* GetSingleton()
			{
				static OnSpellsLearnedRegSet singleton;
				return &singleton;
			}

		private:
			OnSpellsLearnedRegSet();
			OnSpellsLearnedRegSet(const OnSpellsLearnedRegSet&) = delete;
			OnSpellsLearnedRegSet(OnSpellsLearnedRegSet&&) = delete;
			~OnSpellsLearnedRegSet() = default;

			OnSpellsLearnedRegSet& operator=(const OnSpellsLearnedRegSet&) = delete;
			OnSpellsLearnedRegSet& operator=(OnSpellsLearnedRegSet&&) = delete;
		};
	}

	namespace Game
	{
		class OnActorResurrectRegSet : public SKSE::RegistrationSetUnique<const RE::Actor*, bool>
		{
		public:
			using Base = SKSE::RegistrationSetUnique<const RE::Actor*, bool>;

			static OnActorResurrectRegSet* GetSingleton()
			{
				static OnActorResurrectRegSet singleton;
				return &singleton;
			}

		private:
			OnActorResurrectRegSet();
			OnActorResurrectRegSet(const OnActorResurrectRegSet&) = delete;
			OnActorResurrectRegSet(OnActorResurrectRegSet&&) = delete;
			~OnActorResurrectRegSet() = default;

			OnActorResurrectRegSet& operator=(const OnActorResurrectRegSet&) = delete;
			OnActorResurrectRegSet& operator=(OnActorResurrectRegSet&&) = delete;
		};

		class OnActorReanimateStartRegSet : public SKSE::RegistrationSetUnique<const RE::Actor*, const RE::Actor*>
		{
		public:
			using Base = SKSE::RegistrationSetUnique<const RE::Actor*, const RE::Actor*>;

			static OnActorReanimateStartRegSet* GetSingleton()
			{
				static OnActorReanimateStartRegSet singleton;
				return &singleton;
			}

		private:
			OnActorReanimateStartRegSet();
			OnActorReanimateStartRegSet(const OnActorReanimateStartRegSet&) = delete;
			OnActorReanimateStartRegSet(OnActorReanimateStartRegSet&&) = delete;
			~OnActorReanimateStartRegSet() = default;

			OnActorReanimateStartRegSet& operator=(const OnActorReanimateStartRegSet&) = delete;
			OnActorReanimateStartRegSet& operator=(OnActorReanimateStartRegSet&&) = delete;
		};

		class OnActorReanimateStopRegSet : public SKSE::RegistrationSetUnique<const RE::Actor*, const RE::Actor*>
		{
		public:
			using Base = SKSE::RegistrationSetUnique<const RE::Actor*, const RE::Actor*>;

			static OnActorReanimateStopRegSet* GetSingleton()
			{
				static OnActorReanimateStopRegSet singleton;
				return &singleton;
			}

		private:
			OnActorReanimateStopRegSet();
			OnActorReanimateStopRegSet(const OnActorReanimateStopRegSet&) = delete;
			OnActorReanimateStopRegSet(OnActorReanimateStopRegSet&&) = delete;
			~OnActorReanimateStopRegSet() = default;

			OnActorReanimateStopRegSet& operator=(const OnActorReanimateStopRegSet&) = delete;
			OnActorReanimateStopRegSet& operator=(OnActorReanimateStopRegSet&&) = delete;
		};

		class OnWeatherChangeRegSet : public SKSE::RegistrationSet<const RE::TESWeather*, const RE::TESWeather*>
		{
		public:
			using Base = SKSE::RegistrationSet<const RE::TESWeather*, const RE::TESWeather*>;

			static OnWeatherChangeRegSet* GetSingleton()
			{
				static OnWeatherChangeRegSet singleton;
				return &singleton;
			}

		private:
			OnWeatherChangeRegSet();
			OnWeatherChangeRegSet(const OnWeatherChangeRegSet&) = delete;
			OnWeatherChangeRegSet(OnWeatherChangeRegSet&&) = delete;
			~OnWeatherChangeRegSet() = default;

			OnWeatherChangeRegSet& operator=(const OnWeatherChangeRegSet&) = delete;
			OnWeatherChangeRegSet& operator=(OnWeatherChangeRegSet&&) = delete;
		};

		class OnMagicEffectApplyRegMap : public SKSE::RegistrationMapUnique<const RE::TESObjectREFR*, const RE::EffectSetting*, const RE::TESForm*, bool>
		{
		public:
			using Base = SKSE::RegistrationMapUnique<const RE::TESObjectREFR*, const RE::EffectSetting*, const RE::TESForm*, bool>;

			static OnMagicEffectApplyRegMap* GetSingleton()
			{
				static OnMagicEffectApplyRegMap singleton;
				return &singleton;
			}

		private:
			OnMagicEffectApplyRegMap();
			OnMagicEffectApplyRegMap(const OnMagicEffectApplyRegMap&) = delete;
			OnMagicEffectApplyRegMap(OnMagicEffectApplyRegMap&&) = delete;
			~OnMagicEffectApplyRegMap() = default;

			OnMagicEffectApplyRegMap& operator=(const OnMagicEffectApplyRegMap&) = delete;
			OnMagicEffectApplyRegMap& operator=(OnMagicEffectApplyRegMap&&) = delete;
		};

		class OnWeaponHitRegSet : public SKSE::RegistrationSetUnique<const RE::TESObjectREFR*, const RE::TESForm*, const RE::BGSProjectile*, std::uint32_t>
		{
		public:
			using Base = SKSE::RegistrationSetUnique<const RE::TESObjectREFR*, const RE::TESForm*, const RE::BGSProjectile*, std::uint32_t>;

			static OnWeaponHitRegSet* GetSingleton()
			{
				static OnWeaponHitRegSet singleton;
				return &singleton;
			}

		private:
			OnWeaponHitRegSet();
			OnWeaponHitRegSet(const OnWeaponHitRegSet&) = delete;
			OnWeaponHitRegSet(OnWeaponHitRegSet&&) = delete;
			~OnWeaponHitRegSet() = default;

			OnWeaponHitRegSet& operator=(const OnWeaponHitRegSet&) = delete;
			OnWeaponHitRegSet& operator=(OnWeaponHitRegSet&&) = delete;
		};

		class OnMagicHitRegSet : public SKSE::RegistrationSetUnique<const RE::TESObjectREFR*, const RE::TESForm*, const RE::BGSProjectile*>
		{
		public:
			using Base = SKSE::RegistrationSetUnique<const RE::TESObjectREFR*, const RE::TESForm*, const RE::BGSProjectile*>;

			static OnMagicHitRegSet* GetSingleton()
			{
				static OnMagicHitRegSet singleton;
				return &singleton;
			}

		private:
			OnMagicHitRegSet();
			OnMagicHitRegSet(const OnMagicHitRegSet&) = delete;
			OnMagicHitRegSet(OnMagicHitRegSet&&) = delete;
			~OnMagicHitRegSet() = default;

			OnMagicHitRegSet& operator=(const OnMagicHitRegSet&) = delete;
			OnMagicHitRegSet& operator=(OnMagicHitRegSet&&) = delete;
		};

		class OnProjectileHitRegSet : public SKSE::RegistrationSetUnique<const RE::TESObjectREFR*, const RE::TESForm*, const RE::BGSProjectile*>
		{
		public:
			using Base = SKSE::RegistrationSetUnique<const RE::TESObjectREFR*, const RE::TESForm*, const RE::BGSProjectile*>;

			static OnProjectileHitRegSet* GetSingleton()
			{
				static OnProjectileHitRegSet singleton;
				return &singleton;
			}

		private:
			OnProjectileHitRegSet();
			OnProjectileHitRegSet(const OnProjectileHitRegSet&) = delete;
			OnProjectileHitRegSet(OnProjectileHitRegSet&&) = delete;
			~OnProjectileHitRegSet() = default;

			OnProjectileHitRegSet& operator=(const OnProjectileHitRegSet&) = delete;
			OnProjectileHitRegSet& operator=(OnProjectileHitRegSet&&) = delete;
		};

		class OnActorFallLongDistanceRegSet : public SKSE::RegistrationSetUnique<const RE::Actor*, float, float>
		{
		public:
			using Base = SKSE::RegistrationSetUnique<const RE::Actor*, float, float>;

			static OnActorFallLongDistanceRegSet* GetSingleton()
			{
				static OnActorFallLongDistanceRegSet singleton;
				return &singleton;
			}

		private:
			OnActorFallLongDistanceRegSet();
			OnActorFallLongDistanceRegSet(const OnActorFallLongDistanceRegSet&) = delete;
			OnActorFallLongDistanceRegSet(OnActorFallLongDistanceRegSet&&) = delete;
			~OnActorFallLongDistanceRegSet() = default;

			OnActorFallLongDistanceRegSet& operator=(const OnActorFallLongDistanceRegSet&) = delete;
			OnActorFallLongDistanceRegSet& operator=(OnActorFallLongDistanceRegSet&&) = delete;
		};
	}

	namespace FEC
	{
		class OnFECResetRegMap : public SKSE::RegistrationMap<const RE::Actor*, std::uint32_t, bool>
		{
		public:
			using Base = SKSE::RegistrationMap<const RE::Actor*, std::uint32_t, bool>;

			static OnFECResetRegMap* GetSingleton()
			{
				static OnFECResetRegMap singleton;
				return &singleton;
			}

		private:
			OnFECResetRegMap();
			OnFECResetRegMap(const OnFECResetRegMap&) = delete;
			OnFECResetRegMap(OnFECResetRegMap&&) = delete;
			~OnFECResetRegMap() = default;

			OnFECResetRegMap& operator=(const OnFECResetRegMap&) = delete;
			OnFECResetRegMap& operator=(OnFECResetRegMap&&) = delete;
		};
	}
}
