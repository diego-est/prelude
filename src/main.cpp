/* ========================================================================
 *
 *     Filename:  main.cpp
 *  Description:  Prelude testing file
 *       Author:  Diego A. Estrada Rivera
 *      Version:  0.3.0
 *
 * ======================================================================== */
#include "prelude.hpp"
#include <format>
#include <span>

/* === examples === */
fn ack_memo(U128 m, U128 n) noexcept -> U64
{
	if (m == 0)
		return n + 1;
	if (n == 0)
		return memoize<U128, U128>(ack_memo)(m - 1, 1);
	return memoize<U128, U128>(ack_memo)(
	    m - 1, memoize<U128, U128>(ack_memo)(m, n - 1));
}

fn ack(U64 m, U64 n) noexcept -> U64
{
	if (m == 0)
		return n + 1;
	if (n == 0)
		return ack(m - 1, 1);
	return ack(m - 1, ack(m, n - 1));
}

proc Main([[maybe_unused]] std::span<const std::string_view> args) noexcept
    -> I32
{
	std::cout << ack_memo(4, 1) << std::endl;
	std::cout << ack(4, 1) << std::endl;

	return 0;
}
