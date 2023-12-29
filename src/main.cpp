/* ========================================================================
 *
 *     Filename:  main.cpp
 *  Description:  Prelude testing file
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.1
 *
 * ======================================================================== */

/* === examples === */
#include "prelude.hpp"
#include <algorithm>
#include <format>
#include <numeric>
#include <random>

proc generate(I32 n, Char left = '[', Char right = ']') -> String
{
	var rd = std::random_device();
	var str = std::string(n, left) + std::string(n, right);
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

proc main() -> I32
{
	for (var i = 0; i < 9; ++i) {
		let s = std::string(generate(i));
		ignore = println(
		    std::format(" {}: {}", balanced(s) ? "ok" : "bad", s));
	}
}
