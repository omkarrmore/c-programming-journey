# My C Programming Journey

This repository is my personal C practice space. I am learning step by step, so the code is intentionally simple and sometimes a little rough. I want to understand the basics by writing programs, changing them, breaking them, and trying again.

## Start here

Follow the topics in this order:

1. [`fundamentals/`](fundamentals/) — C syntax, variables, input/output, control flow, functions, arrays, and strings.
2. [`practice/`](practice/) — reinforce the fundamentals with focused exercises.
3. [`challenge-practice/`](challenge-practice/) — solve more involved problems using those fundamentals.
4. [`pointers-overlay/`](pointers-overlay/) — learn pointers, arrays, functions, and memory access.
5. [`structures-and-unions/`](structures-and-unions/) — group data into structures and unions, and explore their memory layout.
6. [`enums-and-typedef/`](enums-and-typedef/) — use enums and type aliases, then combine them with structures and unions.
7. [`docs/learning-log.md`](docs/learning-log.md) — read and record progress along the way.

## Roadmap

- [x] Basic C syntax and output
- [x] Variables, input, operators, and conditions
- [x] Loops and simple functions
- [x] Arrays and strings
- [ ] Practice and problem solving
- [x] Pointers and memory (first pass)
- [ ] Structures and unions
- [ ] Enums and typedef
- [ ] File handling and data structures

## Folder guide

| Order | Folder | What is inside |
| --- | --- | --- |
| 1 | [`fundamentals/`](fundamentals/) | My clean starting point, with ten small topic files |
| 2 | [`practice/`](practice/) | Exercises for building confidence with the fundamentals |
| 3 | [`challenge-practice/`](challenge-practice/) | More difficult number, array, string, character, and recursion problems |
| 4 | [`pointers-overlay/`](pointers-overlay/) | Pointer lessons, from basics to function pointers and register-style access |
| 5 | [`structures-and-unions/`](structures-and-unions/) | Structure and union examples, memory layout, and practice |
| 6 | [`enums-and-typedef/`](enums-and-typedef/) | Enum and typedef lessons, embedded patterns, and practice |
| — | [`docs/`](docs/) | Notes about compiling, progress, and sharing this journey |
| — | [`archive/`](archive/) | Original assignment material kept for reference |

Every standalone C program has its own `main()` function. Compile one file at a time:

```sh
gcc -std=c11 -Wall -Wextra -pedantic fundamentals/01_basic_program.c -o basic
./basic
```

More commands are in [`docs/compiling.md`](docs/compiling.md).

## What I am not claiming

This is a learning repository, not a professional C library. Some solutions are first attempts. Some later exercises use ideas that are beyond the fundamentals stage, and those are kept in their own folders.

## Next goals

Continue through structures and unions, then enums and typedef. After that, learn file handling, data structures, and larger C programs.
