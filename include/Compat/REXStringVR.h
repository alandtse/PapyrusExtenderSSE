#pragma once

// CommonLibVR (extern/CommonLibVR) predates the CommonLibSSE "commonlib-shared" split and has
// no REX::STR namespace. commonlib-shared's own REX/STRING.h can't be pulled in directly for VR:
// its REX/REX.h umbrella (and REX/FModule.h) drag in REL/Version.h, which collides with
// CommonLibVR's own REL::Version. This is a self-contained backport of just the REX::STR
// functions this project actually calls, so VR builds get the same string-utility behavior
// SE/AE gets from commonlib-shared.
#ifdef SKYRIMVR

#include <random>

namespace REX::STR
{
	namespace literals
	{
		constexpr std::uint64_t operator""_h(const char* a_str, std::size_t a_len)
		{
			std::uint64_t hash = 0xCBF29CE484222325;
			for (std::size_t i = 0; i < a_len; ++i) {
				hash ^= static_cast<unsigned char>(a_str[i]);
				hash *= 0x00000100000001B3;
			}
			return hash;
		}
	}

	constexpr std::uint64_t CONST_HASH(std::string_view a_str)
	{
		std::uint64_t hash = 0xCBF29CE484222325;
		for (const auto ch : a_str) {
			hash ^= static_cast<unsigned char>(ch);
			hash *= 0x00000100000001B3;
		}
		return hash;
	}

	inline bool ICONTAINS(std::string_view a_str1, std::string_view a_str2)
	{
		if (a_str2.length() > a_str1.length()) {
			return false;
		}

		const auto subrange = std::ranges::search(a_str1, a_str2, [](unsigned char ch1, unsigned char ch2) {
			return std::toupper(ch1) == std::toupper(ch2);
		});

		return !subrange.empty();
	}

	inline bool IEQUALS(std::string_view a_str1, std::string_view a_str2)
	{
		return std::ranges::equal(a_str1, a_str2, [](unsigned char ch1, unsigned char ch2) {
			return std::toupper(ch1) == std::toupper(ch2);
		});
	}

	inline bool IS_EMPTY(const char* a_str)
	{
		return a_str == nullptr || a_str[0] == '\0';
	}

	inline bool IS_ONLY_DIGIT(std::string_view a_str)
	{
		return std::ranges::all_of(a_str, [](unsigned char ch) { return std::isdigit(ch); });
	}

	inline bool IS_ONLY_HEX(std::string_view a_str, bool a_requirePrefix = true)
	{
		if (!a_requirePrefix) {
			return std::ranges::all_of(a_str, [](unsigned char ch) {
				return std::isxdigit(ch);
			});
		} else if (a_str.compare(0, 2, "0x") == 0 || a_str.compare(0, 2, "0X") == 0) {
			return a_str.size() > 2 && std::all_of(a_str.begin() + 2, a_str.end(), [](unsigned char ch) {
				return std::isxdigit(ch);
			});
		}
		return false;
	}

	inline bool REPLACE_ALL(std::string& a_str, std::string_view a_search, std::string_view a_replace)
	{
		if (a_search.empty()) {
			return false;
		}

		std::size_t pos = 0;
		bool        replaced = false;
		while ((pos = a_str.find(a_search, pos)) != std::string::npos) {
			a_str.replace(pos, a_search.length(), a_replace);
			pos += a_replace.length();
			replaced = true;
		}

		return replaced;
	}

	inline std::vector<std::string> SPLIT(const std::string& a_str, std::string_view a_delimiter)
	{
		auto range = a_str | std::ranges::views::split(a_delimiter) | std::ranges::views::transform([](auto&& r) { return std::string_view(r); });
		return { range.begin(), range.end() };
	}

	template <class T>
	T TO_NUM(const std::string& a_str, bool a_hex = false)
	{
		const int base = a_hex ? 16 : 10;

		if constexpr (std::is_same_v<T, double>) {
			return static_cast<T>(std::stod(a_str, nullptr));
		} else if constexpr (std::is_same_v<T, float>) {
			return static_cast<T>(std::stof(a_str, nullptr));
		} else if constexpr (std::is_same_v<T, std::int64_t>) {
			return static_cast<T>(std::stoll(a_str, nullptr, base));
		} else if constexpr (std::is_same_v<T, std::uint64_t>) {
			return static_cast<T>(std::stoull(a_str, nullptr, base));
		} else if constexpr (std::is_signed_v<T>) {
			return static_cast<T>(std::stoi(a_str, nullptr, base));
		} else {
			return static_cast<T>(std::stoul(a_str, nullptr, base));
		}
	}

	inline void TRIM(std::string& a_str)
	{
		constexpr auto not_space = [](unsigned char ch) { return !std::isspace(ch); };
		a_str.erase(std::ranges::find_if(a_str | std::views::reverse, not_space).base(), a_str.end());
		a_str.erase(a_str.begin(), std::ranges::find_if(a_str, not_space));
	}
}

// commonlib-shared's REX::TSingleton is a rename of the same shape CommonLibVR already has as
// REX::Singleton (see extern/CommonLibVR/include/REX/REX/Singleton.h) - just alias it.
namespace REX
{
	template <class T>
	using TSingleton = Singleton<T>;
}

// commonlib-shared's REX/FLOAT.h, ported verbatim (no dependencies beyond <cmath>/<limits>).
namespace REX::FLT
{
	constexpr float EPSILON = std::numeric_limits<float>::epsilon();

	inline bool APPROXIMATELY_EQUAL(const float a, const float b)
	{
		return std::fabs(a - b) <= ((std::fabs(a) < std::fabs(b) ? std::fabs(b) : std::fabs(a)) * EPSILON);
	}

	inline bool ESSENTIALLY_EQUAL(const float a, const float b)
	{
		return std::fabs(a - b) <= ((std::fabs(a) > std::fabs(b) ? std::fabs(b) : std::fabs(a)) * EPSILON);
	}
}

// commonlib-shared's REX::TRandom (REX/TRandom.h) only declares its interface there - the RNG
// itself is implemented in commonlib-shared's compiled .lib, which VR doesn't link. This project
// only ever default-constructs and calls Generate(min, max), so a small self-contained
// std::mt19937_64-backed stand-in is enough (this isn't used for anything save-deterministic).
namespace REX
{
	template <class T>
		requires std::is_arithmetic_v<T>
	class TRandom
	{
	public:
		TRandom() :
			_engine(std::random_device{}())
		{}

		explicit TRandom(std::uint32_t a_seed) :
			_engine(a_seed)
		{}

		explicit TRandom(std::uint64_t a_seed) :
			_engine(a_seed)
		{}

		static constexpr T min() { return std::numeric_limits<T>::min(); }
		static constexpr T max() { return std::numeric_limits<T>::max(); }

		T Generate(T a_min = min(), T a_max = max())
		{
			if constexpr (std::is_floating_point_v<T>) {
				return std::uniform_real_distribution<T>(a_min, a_max)(_engine);
			} else if constexpr (std::is_same_v<T, bool>) {
				return std::uniform_int_distribution<int>(a_min, a_max)(_engine) != 0;
			} else if constexpr (sizeof(T) == 1) {
				using Wide = std::conditional_t<std::is_signed_v<T>, int, unsigned int>;
				return static_cast<T>(std::uniform_int_distribution<Wide>(static_cast<Wide>(a_min), static_cast<Wide>(a_max))(_engine));
			} else {
				return std::uniform_int_distribution<T>(a_min, a_max)(_engine);
			}
		}

	private:
		std::mt19937_64 _engine;
	};
}

// commonlib-shared's REX::TEnum (REX/TEnum.h) has no REL dependency and no equivalent in
// CommonLibVR's own REX/REX/Enum.h (that one predates the TEnum rename) - ported verbatim.
namespace REX
{
	template <class E, class U = std::underlying_type_t<E>>
	class TEnum
	{
	public:
		using enum_type = E;
		using underlying_type = U;

		static_assert(std::is_enum_v<E>, "TEnum<E, ...> must be an enum");
		static_assert(std::is_integral_v<U>, "TEnum<..., U> must be an integral");

		constexpr TEnum() noexcept = default;
		constexpr TEnum(const TEnum&) noexcept = default;
		constexpr TEnum(TEnum&&) noexcept = default;

		template <class U2>
		constexpr TEnum(TEnum<E, U2> a_rhs) noexcept :
			_impl(static_cast<U>(a_rhs.get()))
		{}

		constexpr TEnum(E a_value) noexcept :
			_impl(static_cast<U>(a_value))
		{}

		~TEnum() noexcept = default;

		constexpr TEnum& operator=(const TEnum&) noexcept = default;
		constexpr TEnum& operator=(TEnum&&) noexcept = default;

		template <class U2>
		constexpr TEnum& operator=(TEnum<E, U2> a_rhs) noexcept
		{
			_impl = static_cast<U>(a_rhs.get());
		}

		constexpr TEnum& operator=(E a_value) noexcept
		{
			_impl = static_cast<U>(a_value);
			return *this;
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept { return _impl != static_cast<U>(0); }

		[[nodiscard]] constexpr E operator*() const noexcept { return get(); }
		[[nodiscard]] constexpr E get() const noexcept { return static_cast<E>(_impl); }
		[[nodiscard]] constexpr U underlying() const noexcept { return _impl; }

		friend constexpr bool operator==(TEnum a_lhs, TEnum a_rhs) noexcept { return a_lhs.underlying() == a_rhs.underlying(); }
		friend constexpr bool operator==(TEnum a_lhs, E a_rhs) noexcept { return a_lhs.underlying() == static_cast<U>(a_rhs); }
		friend constexpr bool operator==(E a_lhs, TEnum a_rhs) noexcept { return static_cast<U>(a_lhs) == a_rhs.underlying(); }

	private:
		U _impl{ 0 };
	};

	template <class... Args>
	TEnum(Args...) -> TEnum<std::common_type_t<Args...>, std::underlying_type_t<std::common_type_t<Args...>>>;
}

// commonlib-shared's REX::{TRACE,DEBUG,INFO,WARN,ERROR,CRITICAL,FAIL} log helpers (REX/LOG.h),
// backed here by spdlog directly since CommonLibVR already configures spdlog::default_logger()
// in SKSE::Init (see extern/CommonLibVR/src/SKSE/Logger.cpp) - no separate REX::Impl::Log/Fail
// backend needed.
namespace REX::Impl
{
	template <class... T>
	void Log(spdlog::level::level_enum a_level, const std::format_string<T...> a_fmt, T&&... a_args)
	{
		if (const auto logger = spdlog::default_logger_raw()) {
			logger->log(a_level, std::vformat(a_fmt.get(), std::make_format_args(a_args...)));
		}
	}

	inline void Log(spdlog::level::level_enum a_level, std::string_view a_fmt)
	{
		if (const auto logger = spdlog::default_logger_raw()) {
			logger->log(a_level, a_fmt);
		}
	}
}

// Mirrors commonlib-shared's REX/LOG.h shape exactly (primary variadic template + a <void>
// sentinel specialization for the plain-string, no-args overload, plus explicit deduction
// guides for both) since MSVC's implicit CTAD from the constructor alone did not reliably
// resolve the multi-arg calls used throughout this codebase.
#define PO3_VR_REX_LOG_LEVEL(name, level)                                                                 \
	namespace REX                                                                                         \
	{                                                                                                      \
		template <class... T>                                                                             \
		struct name                                                                                       \
		{                                                                                                  \
			name() = delete;                                                                              \
			explicit name(const std::format_string<T...> a_fmt, T&&... a_args)                            \
			{                                                                                              \
				Impl::Log(level, a_fmt, std::forward<T>(a_args)...);                                      \
			}                                                                                              \
		};                                                                                                 \
		template <>                                                                                       \
		struct name<void>                                                                                 \
		{                                                                                                  \
			name() = delete;                                                                              \
			explicit name(std::string_view a_fmt)                                                         \
			{                                                                                              \
				Impl::Log(level, a_fmt);                                                                  \
			}                                                                                              \
		};                                                                                                 \
		template <class... T>                                                                             \
		name(const std::format_string<T...>&, T&&...)->name<T...>;                                        \
		name(std::string_view)->name<void>;                                                               \
	}

PO3_VR_REX_LOG_LEVEL(TRACE, spdlog::level::trace)
PO3_VR_REX_LOG_LEVEL(DEBUG, spdlog::level::debug)
PO3_VR_REX_LOG_LEVEL(INFO, spdlog::level::info)
PO3_VR_REX_LOG_LEVEL(WARN, spdlog::level::warn)
PO3_VR_REX_LOG_LEVEL(ERROR, spdlog::level::err)
PO3_VR_REX_LOG_LEVEL(CRITICAL, spdlog::level::critical)

#undef PO3_VR_REX_LOG_LEVEL

namespace REX
{
	template <class... T>
	struct FAIL
	{
		FAIL() = delete;

		explicit FAIL(const std::format_string<T...> a_fmt, T&&... a_args)
		{
			Impl::Log(spdlog::level::critical, a_fmt, std::forward<T>(a_args)...);
			SKSE::stl::report_and_fail(std::vformat(a_fmt.get(), std::make_format_args(a_args...)));
		}
	};

	template <>
	struct FAIL<void>
	{
		FAIL() = delete;

		explicit FAIL(std::string_view a_fmt)
		{
			Impl::Log(spdlog::level::critical, a_fmt);
			SKSE::stl::report_and_fail(std::string{ a_fmt });
		}
	};

	template <class... T>
	FAIL(const std::format_string<T...>&, T&&...) -> FAIL<T...>;
	FAIL(std::string_view) -> FAIL<void>;
}

#endif
