#include "prelude.hpp"

proc getLine() noexcept -> String
{
	var str = String();
	getline(std::cin, str);
	return str;
}

proc getChar() noexcept -> Char
{
	var c = Char();
	std::cin >> c;
	return c;
}
