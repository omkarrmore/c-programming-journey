# Pointers in C: Basic to Advanced

Notes for the programs in [`pointers/`](../pointers/). Each section matches one program.
Related notes: [`memorymap.md`](memorymap.md), [`storageclasses.md`](storageclasses.md).

## 1. A pointer stores an address

```c
int x = 10;
int *p = &x;
```

```
   x                p
 +------+        +----------+
 |  10  |  <-----| 0x...e4  |
 +------+        +----------+
 0x...e4          0x...e8
```

- `&x` gives the address of `x`
- `*p` reads (or writes) the value at that address
- A pointer is itself a variable with its own address
- A pointer with no valid target should be `NULL`, never uninitialised

## 2. Call by reference

C always passes arguments by value. To let a function change a caller's
variable, pass its address:

```c
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
swap(&x, &y);
```

## 3. Arrays and pointers

`arr[i]` is defined as `*(arr + i)`. In most expressions an array name decays
to a pointer to its first element. Inside a function, `sizeof` on that
parameter gives the pointer size, not the array size, so pass the length
separately.

## 4. Pointer arithmetic

`p + 1` moves by `sizeof(*p)` bytes, not by one byte. Subtracting two pointers
gives the number of elements between them.

| Expression | Meaning |
|------------|---------|
| `*p++` | read the value, then move the pointer |
| `(*p)++` | increment the value, pointer stays |
| `*++p` | move the pointer, then read |
| `++*p` | increment the value |

## 5. Strings

A string is a `char` array ending in `'\0'`. Walking a pointer until `*p == 0`
is how `strlen` works. Reversal needs only half the length of iterations.

## 6. Dynamic memory

```c
int *a = malloc(n * sizeof *a);     /* sizeof *a stays correct if the type changes */
if (a == NULL) { /* handle failure */ }
/* ... use a ... */
free(a);
a = NULL;
```

- Always check the result of `malloc`
- Every `malloc` needs exactly one `free`
- Use a temporary pointer with `realloc` so a failure does not leak the old block
- Set the pointer to `NULL` after `free`

## 7. Pointer to pointer

Use `int **` when a function must change the caller's pointer (for example to
allocate memory and hand it back), or when working with arrays of strings.

## 8. `const` with pointers

Read the declaration from right to left:

| Declaration | Reads as | Data | Pointer |
|-------------|----------|------|---------|
| `const int *p` | pointer to const int | read-only | can move |
| `int *const p` | const pointer to int | writable | fixed |
| `const int *const p` | const pointer to const int | read-only | fixed |

## 9. Function pointers

```c
typedef int (*binary_op)(int, int);
binary_op op = add;
int r = op(6, 3);
```

Used for dispatch tables, callbacks and comparison functions (`qsort`).

## 10. Common pitfalls

| Bug | Cause | Fix |
|-----|-------|-----|
| Dangling pointer | returning the address of a local variable | heap allocation or a caller-supplied buffer |
| Use after free | pointer still holds the old address | set to `NULL` after `free` |
| Memory leak | missing `free` | one `free` per `malloc` |
| Buffer overrun | copying more than the buffer holds | bounded copies (`snprintf`, `fgets`) |
| Uninitialised pointer | `int *p; *p = 5;` | initialise to `NULL` or a valid address |
| Reverse loop runs the full length | swapping every element twice | loop only while `start < end` |
| Copy loop always writes index 0 | destination index not advanced | advance the destination pointer or index |
| Stray newline after `fgets` | `fgets` keeps `'\n'` | `line[strcspn(line, "\n")] = '\0'` |

## 11. Why this matters for embedded

On a microcontroller a peripheral register is just a memory address. On
STM32F4, GPIOA's output data register sits at `0x40020014`:

```c
#define GPIOA_ODR (*(volatile uint32_t *)0x40020014)
GPIOA_ODR |= (1U << 5);     /* set PA5 */
```

`volatile` tells the compiler the value can change outside the program's
control, so every access must really happen. Program 11 reproduces the same
pattern on a PC using a variable as a stand-in register.

## Practice problems to try next

- [ ] Write `my_strcat` and `my_strcmp` with pointers only
- [ ] Reverse an integer array in place using two pointers
- [ ] Find the second largest element using pointers
- [ ] Dynamic 2D array (array of pointers, then one contiguous block)
- [ ] Implement a singly linked list using `struct node *`
- [ ] Callback-based `map` and `filter` over an int array

## Next

Structures and unions, then linked lists and other data structures built on
the pointer foundation from this section.
