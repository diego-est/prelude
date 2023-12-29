# C++ Prelude
Modern C++ makes me sad when I look at it. So this is my attempt to change several of the defaults we use to code in C++.

## Types
A mix of the naming scheme in Rust and HolyC is very aesthetically pleasing.
Types become terse with only the information you need at a first glance.
Furthermore, for consistency, all types should begin with capital letters.

### Numeric Types
| Prelude   | Vanilla |
|-----------|---------|
| `Size`    | `std::size_t` |
| `U8`      | `uint8_t` |
| `U16`     | `uint16_t` |
| `U32`     | `uint32_t` |
| `U64`     | `uint64_t` |
| `I8`      | `int8_t` |
| `I16`     | `int16_t` |
| `I32`     | `int32_t` |
| `I64`     | `int64_t` |
| `F32`     | `float` |
| `F64`     | `double` |

### Other Types
| Prelude   | Vanilla |
|-----------|---------|
| `Unit`    | `void` |
| `Void`    | N/A |
| `Bool`    | `bool` |
| `Ptr<T>`  | `T*` |
| `Ref<T>`  | `T&` |

In most situations, it is clearer to write the type as a `Ptr<T>` than a `T*`.
Same goes for `Ref<T>`.
This also remains consistent with the implementation of smart pointers in the
standard library, for example `std::unique_ptr<T>`.

## Keywords
| Prelude   | Vanilla |
|-----------|---------|
| `let`     | `auto const` |
| `var`     | `auto` |
| `fn`      | `[[nodiscard]] auto constexpr` |
| `proc`    | `[[nodiscard]] auto` |
| `ignored = foo()` | `static_cast<void>(foo())`
| `fst`     | `std::get<0>` |
| `snd`     | `std::get<1>` |
| `thr`     | `std::get<2>` |

You define terms as `let x = 0;`. If you need the term to be of any specific numeric type
then use suffixes like: `let x = 0u;` (x is unsigned).
If you need a variable term then use the `var` keyword instead. The motivation
for this is that you should prefer immutable terms before considering mutable
variables.

All functions should be `[[nodiscard]]` and be annotated with trailing return
types.
If you need to ignore the return value of a function then use `ignored = ...` to
explicitly ignore it.

`fst`, `snd` and `thr` naming conventions are taken from Haskell. The motivation
being that `std::get<#>` is extremely verbose for accessing the
first/second/third/etc members of that tuple.

NOTE: `constexpr` being used for the `fn` keyword is currently being tested. The
motivation for this is to achieve something akin to `[[pure]]`.

# TODO:
- [ ] sensible IO operations
- [ ] Functor interface
- [ ] Monoid interface
- [ ] Applicative interface
- [ ] Alternative interface
- [ ] Monad interface ??