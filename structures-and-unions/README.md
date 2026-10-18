# Structures and Unions in C

Part of my **C Programming Journey**. Each topic has its own folder with a `README.md` (explanation) and a small `.c` program (tested example).

All examples compile cleanly with `gcc -Wall -Wextra`. Output shown in each README is from a little-endian x86 machine, so byte orders and sizes can differ on other targets.

## Topics

| # | Topic | What it covers |
|---|---|---|
| 01 | [Structures: the basics](01-structures-basics/) | Declaring, `typedef`, initialization, copying |
| 02 | [Accessing members](02-accessing-members/) | `.` vs `->` |
| 03 | [Nested and self-referential](03-nested-and-self-referential/) | Structures inside structures, linked-list nodes |
| 04 | [Array of structures](04-array-of-structures/) | Arrays of records, memory layout |
| 05 | [Pointer to array of structures](05-pointer-to-array-of-structures/) | Pointer arithmetic, passing arrays to functions, `const`, dynamic arrays |
| 06 | [Passing structures to functions](06-passing-structures-to-functions/) | By value vs by pointer, returning structures |
| 07 | [Padding and alignment](07-padding-and-alignment/) | Why `sizeof` grows, `offsetof`, `packed` |
| 08 | [Bit fields](08-bit-fields/) | Packing flags into bits |
| 09 | [Unions](09-unions/) | Shared memory, type punning, endianness |
| 10 | [Structure vs union](10-structure-vs-union/) | Side-by-side comparison |
| 11 | [Unions in embedded work](11-unions-in-embedded/) | Registers, UART/SPI bytes, tagged unions |
| 12 | [Common mistakes](12-common-mistakes/) | Bugs to watch for |
| 13 | [Practice questions](13-practice-questions/) | Questions, answers and solutions |

## Build and run everything

```bash
make          # compiles every example into ./bin/
make run      # compiles and runs every example
make clean
```

Or compile one example by hand:

```bash
gcc -Wall -Wextra -o demo 05-pointer-to-array-of-structures/pointer_to_array.c
./demo
```

## Suggested order

Read 01 to 06 first (structures and how to pass them around), then 07 and 08 (memory layout), then 09 to 11 (unions), and finish with 12 and 13.
