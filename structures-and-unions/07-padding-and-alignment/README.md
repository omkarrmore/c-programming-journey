# 07: Structure padding and alignment

The compiler inserts unused **padding bytes** so each member sits at an address suited to its type. So `sizeof` a structure can be larger than the sum of its members, and member order changes the size.

```c
struct A { char a; int b; char c; };   // 12 bytes
struct B { int b; char a; char c; };   //  8 bytes
```

Layout of `struct A` (4-byte `int`):

```
offset: 0   1 2 3   4 5 6 7   8   9 10 11
        a   pad     b         c   pad
```

Layout of `struct B`:

```
offset: 0 1 2 3   4   5   6 7
        b         a   c   pad
```

## Key points

- Declare members from largest to smallest to reduce padding.
- `offsetof(struct A, b)` from `<stddef.h>` shows where a member actually sits.
- Padding bytes have unspecified contents, so comparing two structures with `memcmp` can give wrong results.
- Total size is rounded up so that every element of an array of the structure stays aligned.
- `__attribute__((packed))` (GCC/Clang) removes padding. It is useful for protocol frames, but access can be slower, and some MCUs fault on unaligned access. Use it deliberately.

## Example

[`padding.c`](padding.c)

```
sizeof(struct A) = 12
  offset a=0 b=4 c=8
sizeof(struct B) = 8
  offset b=0 a=4 c=5
sizeof(struct P) = 6 (packed)
```

Previous: [06 Passing structures to functions](../06-passing-structures-to-functions/) | Next: [08 Bit fields](../08-bit-fields/)
