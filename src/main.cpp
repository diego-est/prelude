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
	var s = String();
	while (true) {
		ignore = print(s);
		var a = getLine();
		s+= "Give me two floating point numbers: ";
		s += a;
	}


	return 0;
}
