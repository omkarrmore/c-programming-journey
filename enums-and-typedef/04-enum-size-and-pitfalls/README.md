# 04: Enum size and pitfalls

## Size

An enum variable is stored as an integer type chosen by the compiler. It must be able to hold every enumerator.

```c
sizeof(enum Color)   // 4 on a typical desktop compiler
```

- The exact size is **implementation-defined**.
- Some embedded compilers (for example `arm-none-eabi-gcc` with `-fshort-enums`) pick the smallest type that fits, so an enum may be 1 byte there.
- Never assume `sizeof(enum X) == sizeof(int)` in code that is sent over a communication link or stored in a file. Convert to a fixed-width type such as `uint8_t` first.

## Pitfalls

1. **C does not restrict the value.** `enum Color c = (enum Color)7;` compiles and runs, even though 7 is not an enumerator.
2. **Enumerators are plain ints.** `RED + GREEN + BLUE` is `3`, and `BLUE == 2` is true.
3. **Different enum types compare freely.** `GREEN == SMALL` compiles and is true if both are 1. The compiler will not stop you mixing them.
4. **Values from outside are untrusted.** A byte from UART, a file or a sensor may not be a valid enumerator. Check the range before casting.

```c
int fromUart = 9;
if (fromUart >= RED && fromUart <= BLUE)
    c = (enum Color)fromUart;
else
    printf("rejected %d\n", fromUart);
```

(With a `COUNT` entry the check is `fromUart >= 0 && fromUart < COLOR_COUNT`.)

## Key points

- Treat an enum as a **naming convenience**, not a safety feature.
- Validate external input before converting it to an enum.
- Use explicit casts when you convert between an enum and an integer, to show the intent.
- Prefer a `switch` without `default` so the compiler warns about missing cases.

## Example

[`enum_pitfalls.c`](enum_pitfalls.c)

```
sizeof(enum Color) = 4
sizeof(enum Big)   = 4
sizeof(int)        = 4
c = 7 (not RED, GREEN or BLUE!)
RED + GREEN + BLUE = 3
BLUE == 2 ? yes
GREEN == SMALL ? yes
rejected 9: not a valid Color
```

Previous: [03 Enums with switch](../03-enums-with-switch/) | Next: [05 typedef basics](../05-typedef-basics/)
