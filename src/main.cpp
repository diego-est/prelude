/* ========================================================================
 *
 *     Filename:  main.cpp
 *  Description:  Prelude testing file
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.2
 *
 * ======================================================================== */
#include "prelude.hpp"

/* === examples === */
/* test accuracy of type sizes */
/*
#include <iostream>
#include <format>

proc Main([[maybe_unused]] std::span<const std::string_view> args) noexcept -> I32
{
	ignore = println(std::format("BF16: {}", CHAR_BIT * sizeof(BF16)));
	ignore = println(std::format("float: {}", CHAR_BIT * sizeof(float)));
	ignore = println(std::format("F32: {}", CHAR_BIT * sizeof(F32)));
	ignore = println(std::format("D32: {}", CHAR_BIT * sizeof(D32)));
	ignore = println(std::format("double: {}", CHAR_BIT * sizeof(double)));
	ignore = println(std::format("F64: {}", CHAR_BIT * sizeof(F64)));
	ignore = println(std::format("D64: {}", CHAR_BIT * sizeof(D64)));
	// Err: F80 is the same as F128
	// ignore = println(std::format("F80: {}", CHAR_BIT * sizeof(F80)));
	ignore = println(std::format("long double: {}", CHAR_BIT * sizeof(long double)));
	ignore = println(std::format("F128: {}", CHAR_BIT * sizeof(F128)));
	ignore = println(std::format("D128: {}", CHAR_BIT * sizeof(D128)));


	return 0;
}
*/
#include <random>
#include "prelude.hpp"

proc generate(I32 n, Char left = '[', Char right = ']') -> String
{
	var rd = std::random_device();
	var str = String(n, left) + String(n, right);
	std::shuffle(str.begin(), str.end(), std::mt19937(rd()));

	return str;
}

fn balanced(std::string_view str, Char left = '[', Char right = ']') -> Bool
{
	var count = 0;
	for (let& ch : str) {
		if (ch == left)
			count++;
		else if (ch == right)
			if (--count < 0)
				return false;
	}

	return count == 0;
}

proc Main([[maybe_unused]] const std::span<const std::string_view> args) -> I32
{
	for (var i = 0; i < 9; ++i) {
		let s = String(generate(i));
		ignore = println(
		    std::format(" {}: {}", balanced(s) ? "ok" : "bad", s));
	}
	return 0;
}
