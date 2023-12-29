/* ========================================================================
 *
 *     Filename:  main.cpp
 *  Description:  Prelude testing file
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <cmath>
#include <iostream>
#include "prelude.hpp"

/* === examples === */
fn square(I32 x) -> I32
{
	return x * x;
}

fn fib(U64 n) -> U64
{
	if (n <= 1) return n;

	return fib(n - 1) + fib(n - 2);
}

fn fact(I32 x) -> I32
{
	if (x <= 1) return 1;

	return x * fact(x - 1);
}

fn test(U64 n)
{
	let fact = [] [[gnu::const]] (U64 x) {
		var a = 1lu;
		while (x-- > 0) {
			a *= (a + 1);
		}

		return a;
	};

	var b = fact(n);
	while (b-- > 0) {
		var c = n * n * n * n * n;
		while (c-- > 0) {  }
	}

	return n;
}

proc main() -> I32
{
	ignore = println("Hello world!");
	return 0;
}

