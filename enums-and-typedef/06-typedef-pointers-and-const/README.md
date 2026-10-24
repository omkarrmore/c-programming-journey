# 06: typedef with pointers and `const`

This is where `typedef` and `#define` really differ.

```c
typedef int *IntPtr;      // a real type: "pointer to int"
#define INTPTR int *      // just text
```

## 1. Declaring two variables

```c
IntPtr a, b;     // both are int *
INTPTR c, d;     // expands to: int * c, d;   ->  c is int *, d is a plain int
```

The `*` in `int *c, d;` attaches to `c` only. With the macro you get one pointer and one int.

## 2. How `const` binds

```c
const IntPtr p1 = &x;    // const applies to the TYPE IntPtr  ->  int *const p1
*p1 = 10;                // OK: the int can change
// p1 = &y;              // ERROR: the pointer itself is const

const INTPTR p2 = &x;    // text becomes: const int * p2   ->  pointer to const int
p2 = &y;                 // OK: the pointer can move
// *p2 = 20;             // ERROR: the int is read-only through p2
```

| Declaration | Meaning | Can change `*p`? | Can change `p`? |
|---|---|---|---|
| `const IntPtr p` | `int *const p` (const pointer to int) | Yes | No |
| `const INTPTR p` | `const int *p` (pointer to const int) | No | Yes |

With a `typedef`, `const` applies to the **whole pointer type**. With `#define`, `const` is pasted next to `int` first.

## Key points

- `typedef` creates a true type alias. `#define` is raw text substitution.
- **Expand the macro as text first, then read the declaration.** This one habit solves most tracing questions.
- Reading `const` with pointers: read the declaration right to left (`int *const p` is "p is a const pointer to int").
- Prefer `typedef` when you want a type alias. Prefer not to hide a `*` behind a typedef name at all, unless the type is intentionally opaque.

## Example

[`typedef_vs_define.c`](typedef_vs_define.c)

```
sizeof(a)=8 sizeof(b)=8
sizeof(c)=8 sizeof(d)=4
x=10 *p1=10 *p2=2
```

`d` is only 4 bytes because it is an `int`, not a pointer. (On a 32-bit target `a` and `b` would be 4 bytes, so compare `sizeof(d)` with `sizeof(c)` rather than relying on the absolute numbers.)

Previous: [05 typedef basics](../05-typedef-basics/) | Next: [07 typedef for function pointers](../07-typedef-function-pointers/)
