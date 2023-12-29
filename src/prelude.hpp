/* ========================================================================
 *
 *     Filename:  prelude.hpp
 *  Description:  C++ sensible prelude
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.1
 *
 * ======================================================================== */
#pragma once

/* Use sensible numberic types */
#include <cstdint>

using Size = std::size_t;

typedef float F32;
typedef double F64;

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

typedef int8_t I8;
typedef int16_t I16;
typedef int32_t I32;
typedef int64_t I64;

typedef bool Bool;

/* use sensible keywords */
#define let auto const
#define var auto
#define fn [[nodiscard]] auto constexpr
#define proc [[nodiscard]] auto

/* Apparently this isn't included in <tuple>
 * https://en.cppreference.com/w/cpp/utility/tuple/ignore
 */
namespace detail {
	struct ignore_t {
		template <typename T>
		constexpr // required since C++14
		void operator = (T&&) const noexcept {}
	};
}
inline constexpr detail::ignore_t ignore; // 'const' only until C++17

/* use sensible tuple managing functions */
#define fst std::get<0>
#define snd std::get<1>
#define thr std::get<2>

/* use sensible data typing */
template <typename T>
using Ref = T&;

template <typename T>
using Ptr = T*;

/* Unit type */
enum class Unit {
	unit
};

/* Void type }:) */
enum class Void {
};
