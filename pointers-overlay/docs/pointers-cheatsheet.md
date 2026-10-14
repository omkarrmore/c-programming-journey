# Pointers Cheat Sheet

## Operators

| Syntax | Meaning |
|--------|---------|
| `int *p` | declare `p` as pointer to `int` |
| `&x` | address of `x` |
| `*p` | value at the address stored in `p` |
| `p->m` | same as `(*p).m` (struct member) |
| `**pp` | value at the address that `*pp` points to |

## Equivalences

```c
arr[i]   ==  *(arr + i)
&arr[i]  ==  arr + i
p[i]     ==  *(p + i)
```

## Pointer arithmetic

```c
p + n      // moves n * sizeof(*p) bytes
p - q      // number of ELEMENTS between two pointers (same array)
*p++       // read, then advance
(*p)++     // increment the value
```

## const

```c
const int *p        // data read-only
int *const p        // pointer fixed
const int *const p  // both fixed
```

Read right to left.

## Dynamic memory

```c
T *a = malloc(n * sizeof *a);      // uninitialised
T *z = calloc(n, sizeof *z);       // zeroed
T *t = realloc(a, m * sizeof *a);  // resize; check t before overwriting a
free(a); a = NULL;
```

## Function pointers

```c
typedef int (*binary_op)(int, int);
binary_op op = add;
op(2, 3);
```

## Embedded register access

```c
#define REG (*(volatile uint32_t *)ADDRESS)
REG |=  (1U << n);    // set bit
REG &= ~(1U << n);    // clear bit
REG ^=  (1U << n);    // toggle bit
(REG >> n) & 1U       // read bit
```

## Debugging checklist

- Is the pointer initialised? Is it `NULL`-checked before use?
- Does every `malloc` have exactly one `free`?
- Is any pointer used after `free`?
- Is any loop reading or writing past the last element?
- Does a function return the address of a local variable?
- Is `sizeof` being applied to a pointer where an array size was meant?
