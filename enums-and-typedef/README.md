# Enums and typedef in C

Part of my **C Programming Journey**. Each topic has its own folder with a `README.md` (explanation) and a small `.c` program (tested example).

All examples compile cleanly with `gcc -Wall -Wextra -std=gnu11`. Output shown in each README is from a 64-bit little-endian x86 machine, so sizes can differ on other targets (for example, an embedded ARM compiler).

## Topics

| # | Topic | What it covers |
|---|---|---|
| 01 | [Enum basics](01-enum-basics/) | Declaring, auto-increment, explicit values, `COUNT` trick |
| 02 | [Enum vs `#define`](02-enum-vs-define/) | Text substitution trap, scope, grouping |
| 03 | [Enums with `switch`](03-enums-with-switch/) | State machines, name tables, `-Wswitch` |
| 04 | [Enum size and pitfalls](04-enum-size-and-pitfalls/) | Underlying type, out-of-range values, validation |
| 05 | [typedef basics](05-typedef-basics/) | Aliases for types, structs, arrays |
| 06 | [typedef with pointers and `const`](06-typedef-pointers-and-const/) | `typedef` vs `#define`, how `const` binds |
| 07 | [typedef for function pointers](07-typedef-function-pointers/) | Operation tables, callbacks |
| 08 | [typedef in embedded code](08-typedef-in-embedded/) | `uint8_t`, `volatile` register types, bit macros |
| 09 | [Tagged union revisited](09-tagged-union-revisited/) | Enum tag + union + struct (links back to Structures and Unions) |
| 10 | [Common mistakes](10-common-mistakes/) | Bugs to watch for |
| 11 | [Practice questions](11-practice-questions/) | Questions, answers and solutions |

## Build and run everything

```bash
make          # compiles every example into ./bin/
make run      # compiles and runs every example
make clean
```

Or compile one example by hand:

```bash
gcc -Wall -Wextra -o demo 03-enums-with-switch/state_machine.c
./demo
```

## Suggested order

Read 01 to 04 (enums), then 05 to 07 (typedef), then 08 and 09 (embedded patterns that combine everything), and finish with 10 and 11.
