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
// test accuracy of type sizes

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
