/* ========================================================================
 *
 *     Filename:  prelude.hpp
 *  Description:  C++ sensible prelude - Declarations
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.4
 *
 * ======================================================================== */
#pragma once

/* === Numeric Types === */
#include <cstdint>
#include <limits.h>
using Size = std::size_t;

/* Floating Point */
// brain floating point
// see https://en.wikipedia.org/wiki/Bfloat16_floating-point_format
typedef __bf16 BF16;
typedef _Float16 F16;
typedef float F32;
static_assert(sizeof(F32) * CHAR_BIT == 32); //
typedef double F64;
static_assert(sizeof(F64) * CHAR_BIT == 64);
#if __float80_max < __float128_max
	typedef __float80 F80; // sometimes is the same as F128
#endif
typedef __float128 F128;

// decimal floating points
// see decimal32/64/128 in https://en.wikipedia.org/wiki/IEEE_754
//typedef float __attribute__((mode(SD))) D32;
//typedef float __attribute__((mode(DD))) D64;
//typedef float __attribute__((mode(TD))) D128;

/* Integer */
typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef __uint128_t U128;

typedef int8_t I8;
typedef int16_t I16;
typedef int32_t I32;
typedef int64_t I64;
typedef __int128_t I128;

// generic Integer type
typedef int_fast32_t Int;

/* === Other Types === */
typedef bool Bool;
typedef char Char;
typedef const char * CString;

#include <vector>
template <typename T> using Vector = std::vector<T>;

#include <string>
using String = std::string;
using namespace std::string_literals;

// Unit type
enum class Unit { unit };

// Void type
enum class Void {};

// Pointer types
template <typename T> using Ref = T&;

template <typename T> using Handle = T*;

/* === Keywords === */
template <class T>
concept Auto = true;
#define let auto const
#define var auto

#define fn [[nodiscard, gnu::const]] auto
#define proc [[nodiscard]] auto

/* This is included as a static member variable of <tuple>.
 * However, there is no way to bring the std::ignore namespace static variable
 * into the current scope. This is a way to do that.
 * https://en.cppreference.com/w/cpp/utility/tuple/ignore
 */
namespace detail {
struct ignore_t {
	template <typename T>
	constexpr // required since C++14
	    void
	    operator = (T&&) const noexcept {}
};
} // namespace detail
inline constinit const detail::ignore_t ignore; // changed to constinit

// manage tuples better
#define fst std::get<0>
#define snd std::get<1>
#define thr std::get<2>

/* === Miscellaneous Functions */
#include <concepts>
#include <type_traits>
#include <unordered_map>

// key_hash comes from this stack overflow: https://stackoverflow.com/questions/20834838/using-tuple-in-unordered-map
// this is necessary so we can index the hashmap using tuples
template <class... Types> struct n_tuple_key_hash {
	fn operator()(std::tuple<Types...> const& args) const noexcept -> size_t
	{
		return std::apply([](var... t) { return (t ^ ...); }, args);
	}
};

template <class... Types> fn memoize(let&& op) noexcept
{
	static var mp =
	    std::unordered_map<std::tuple<Types...>,
			       std::invoke_result_t<decltype(op), Types...>,
			       n_tuple_key_hash<Types...>>();

	return [&](Types... types) noexcept {
		let& t = std::make_tuple(types...);
		return mp.contains(t) ? mp.at(t) : mp[t] = op(types...);
	};
}

/* Sensible IO */
#include <iostream>
proc getLine() noexcept -> String;

proc getChar() noexcept -> Char;

proc print(const std::string_view& f) noexcept -> Unit;

proc println(const std::string_view& f) noexcept -> Unit;
