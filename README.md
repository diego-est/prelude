# C++ Prelude
Modern C++ makes me sad when I look at it. So this is my attempt to change
several of the defaults we use to code in C++. Additionally, several features
that are missing in the language (but enabled through obscure compiler macros
and directives) are enabled.

## Includes
Several containers and algorithms can be included using the `CONTAINERS` or
`ALGORITHMS` or `IO` directive. I use these very frequently, others might not. For that
reason they are opt-in. To enable them define the the containers or algorithms
directive **before** including the header.

Like this:
```cpp
#define CONTAINERS
#define ALGORITHMS
#define IO
#include "prelude.hpp"
```
The following containers are included:
 - unordered_map
 - unordered_set
 - queue
 - stack
 - list
 - span

The following algorithms are included:
 - algorithm
 - ranges
 - numeric

 The following io headers are included:
 - format
 - fstream

The following headers are included by default:
 - cstdint
 - limits.h
 - iostream

## Types
A mix of the naming scheme in Rust and HolyC is very aesthetically pleasing.
Types become terse with only the information you need at a first glance.
Furthermore, for consistency, all types should begin with capital letters.

### Numeric Types

#### Floats
Most of the floating types that are mentioned in [IEEE 754](https://en.wikipedia.org/wiki/IEEE_754).
| Prelude   | Vanilla |
|-----------|---------|
| `BF16`    | N/A |
| `F16`     | N/A |
| `F32`     | `float` |
| `D32`     | N/A |
| `F64`     | `double` |
| `D64`     | N/A |
| `F80`     | N/A or `long double` |
| `D128`    | N/A |
| `F128`    | N/A |

Additional information on the [brain floating data type](https://en.wikipedia.org/wiki/Bfloat16_floating-point_format).

| Prelude   | Vanilla |
|-----------|---------|
| `Size`    | `std::size_t` |
| `Int`     | N/A |
| `U8`      | `uint8_t` |
| `U16`     | `uint16_t` |
| `U32`     | `uint32_t` |
| `U64`     | `uint64_t` |
| `U128`    | N/A |
| `I8`      | `int8_t` |
| `I16`     | `int16_t` |
| `I32`     | `int32_t` |
| `I64`     | `int64_t` |
| `I128`    | N/A |

These changes beg the question: What is wrong with `int`?
Well `int` would be a perfectly valid type if C++ supported Big Integers like
Java does. The problem is `int` is fixed to a type that is _sometimes_ 32-bits
and other times something else. I think this is very inelegant and needlessly
terse. It is better to simply know what kind of integer and bit-width it takes
up.

The only exception to this rule being `Size` and `Int`. For the former we want
to preserve the ability to scale depending on what system runs the binary. For
the latter we want to optimize the CI development cycle, so the less worries the
better. If you want an `Int` then have an `Int`.

### Other Types
| Prelude   | Vanilla |
|-----------|---------|
| `Unit`    | `void` |
| `Void`    | N/A |
| `Bool`    | `bool` |
| `Char`    | `char` |
| `Handle<T>`  | `T*` |
| `Ref<T>`  | `T&` |
| `Vector`  | `std::vector<T>` |
| `String`  | `std::string` |
| `CString` | `const char *` |

In most situations, it is clearer to write the type as a `Handle<T>` than a `T*`.
Same goes for `Ref<T>`.
This also remains consistent with the implementation of smart pointers in the
standard library, for example `std::unique_ptr<T>`.

`std::string_literals` are enabled by default.

## Keywords
| Prelude   | Vanilla |
|-----------|---------|
| `let`     | `auto const` |
| `var`     | `auto` |
| `fn`      | `[[nodiscard, gnu::const]] auto` |
| `proc`    | `[[nodiscard]] auto` |
| `ignored = foo();` | `static_cast<void>(foo());`
| `fst`     | `std::get<0>` |
| `snd`     | `std::get<1>` |
| `thr`     | `std::get<2>` |

You define terms as `let x = 0;`. If you need the term to be of any specific
numeric type then use suffixes like: `let x = 0u;` (x is unsigned).
If you need a variable term then use the `var` keyword instead. The motivation
for this is that you should prefer immutable terms before considering mutable
variables.

All functions should be `[[nodiscard]]` and be annotated with trailing return
types.
If you need to ignore the return value of a function then use `ignore = ...` to
explicitly ignore it.
Additionally, the term `fn` (function) should be used in its most literal
mathematical sense, for a given input it will always produce the same output.
If you want to do something that requires side effects then use the `proc`
(procedure) keyword instead.

`fst`, `snd` and `thr` naming conventions are taken from Haskell. The motivation
being that `std::get<#>` is extremely verbose for accessing the
first/second/third/etc members of that tuple.

## Better Main
The way `main` is defined for use is very old. It is not type safe and uses old
types like c-strings. We can, instead, make a better `Main` that is the one we
define our program in and forward the arguments in a type-safe manner.

Implementation taken from [C++ Weekly ep 361 by Jason Turner](https://www.youtube.com/watch?v=zCzD9uSDI8c)
```cpp
I32 main(const I32 argc, const Handle<const CString> argv) {
    // declare function inside main
	proc Main(std::span<const std::string_view>) noexcept -> I32;

    // pass arguments to safe main
	let args = std::vector<std::string_view>(argv, std::next(argv, static_cast<std::ptrdiff_t>(argc)));
	return Main(args);
}
```

NOTE: It has been mentioned that `argv` has historically been used for passing
sensitive information like passwords to programs. In that case, the array used
to store the different arguments is chopped up to remove the sensitive
information. For now, this method does not allow do that. Furthermore,
sending sensitive information through command line arguments is a bad idea IMO.

### Short example
Solution for Rosetta Code "[Balanced Brackets](https://rosettacode.org/wiki/Balanced_brackets)"
using this prelude.
```cpp
#include <format>
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
}
```

# TODO:
- [ ] Add algorithms
- [ ] Improve range algorithms
