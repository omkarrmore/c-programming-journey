# My C Programming Journey

This repository is my personal C practice space. I am learning step by step, so the code is intentionally simple and sometimes a little rough. I want to understand the basics by writing programs, changing them, breaking them, and trying again.

## Start here

1. Begin with [`fundamentals/`](fundamentals/).
2. Move to [`practice/`](practice/) when variables, conditions, loops, functions, arrays, and strings feel comfortable.
3. Try [`challenge-practice/`](challenge-practice/) after that. These exercises are a little more involved.
4. Continue with [`pointers/`](pointers/) for pointers and memory.
5. Read my progress in [`docs/learning-log.md`](docs/learning-log.md).

## Roadmap

- [x] Basic C syntax and output
- [x] Variables, input, operators, and conditions
- [x] Loops and simple functions
- [x] Arrays and strings
- [ ] More problem solving
- [ ] Better input validation
- [x] Pointers (first pass: basics to function pointers)
- [ ] Advanced C

## Folder guide

| Folder | What is inside |
| --- | --- |
| `fundamentals` | My clean starting point, with ten small topic files |
| `practice` | Repeated exercises for building confidence |
| `challenge-practice` | More difficult number, array, string, character, and recursion problems |
| `pointers` | Eleven programs from pointer basics to function pointers and register-style access |
| `docs` | Notes about compiling, memory, pointers, progress, and sharing this journey |
| `archive` | Original assignment material kept for reference |

Every standalone C program has its own `main()` function. Compile one file at a time:

```sh
gcc -std=c11 -Wall -Wextra -pedantic fundamentals/01_basic_program.c -o basic
./basic
```

More commands are in [`docs/compiling.md`](docs/compiling.md).

## What I am not claiming

This is a learning repository, not a professional C library. Some solutions are first attempts. Some later exercises use ideas that are beyond the fundamentals stage, and those are kept in their own folders.

## Next goals

I have finished a first pass through pointers and memory. Next I plan to learn structures and unions, file handling, data structures, and larger C programs.
