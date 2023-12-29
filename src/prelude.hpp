/* ========================================================================
 *
 *     Filename:  prelude.hpp
 *  Description:  C++ sensible prelude
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.2
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
typedef char Char;

#include <vector>
template <typename T>
using Vector = std::vector<T>;

#include <string>
using String = std::string;
using namespace std::string_literals;

/* Unit type */
enum class Unit {
	unit
};

/* Void type }:) */
enum class Void {
};

/* Pointer types */
template <typename T>
using Ref = T&;

template <typename T>
using Ptr = T*;

/* use sensible keywords */
#define let auto const
#define var auto
#define fn [[nodiscard, gnu::const]] auto
#define proc [[nodiscard]] auto
#define Inst auto

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

/* Sensible IO */
#include <iostream>

proc print(let &x) noexcept -> Unit
{
	std::cout << x;
	return Unit();
}

proc println(let &x) noexcept -> Unit
{
	std::cout << x << std::endl;
	return Unit();
}

proc getChar() noexcept -> Char;

proc getLine() noexcept -> String;
