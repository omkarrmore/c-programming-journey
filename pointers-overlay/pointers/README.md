# Pointers

Small programs that go from the first `&` and `*` to function pointers and
register-style access in embedded C. Notes for each topic are in
[`docs/pointers.md`](../docs/pointers.md) and a quick reference is in
[`docs/pointers-cheatsheet.md`](../docs/pointers-cheatsheet.md).

| # | Program | Concept |
| --- | --- | --- |
| 01 | `01_pointer_basics.c` | What a pointer stores, `&`, `*`, `NULL` |
| 02 | `02_call_by_reference.c` | Swap, output parameters, why C is pass-by-value |
| 03 | `03_pointers_and_arrays.c` | `arr[i] == *(arr + i)`, array decay |
| 04 | `04_pointer_arithmetic.c` | Scaled steps, pointer difference, `*p++` vs `(*p)++` |
| 05 | `05_strings_with_pointers.c` | `strlen`/`strcpy`/reverse, word-by-word in-place reversal |
| 06 | `06_dynamic_memory.c` | `malloc`, `calloc`, `realloc`, `free` |
| 07 | `07_pointer_to_pointer.c` | `int **`, changing the pointer itself, arrays of strings |
| 08 | `08_const_with_pointers.c` | `const int *`, `int *const`, reading right to left |
| 09 | `09_function_pointers.c` | Dispatch tables, callbacks, `qsort` |
| 10 | `10_pointer_pitfalls.c` | Dangling pointers, overruns, leaks, safe patterns |
| 11 | `11_register_access_demo.c` | Memory-mapped register access, bit manipulation |

## Build and run

```sh
cd pointers
make            # build everything into build/
make run P=03   # run one program
make clean
```

Or one file at a time, like the rest of the repository:

```sh
gcc -std=c11 -Wall -Wextra -pedantic pointers/01_pointer_basics.c -o pointers01
./pointers01
```

Program 05 reads a line from the keyboard and falls back to a default sentence
if no input is given.
