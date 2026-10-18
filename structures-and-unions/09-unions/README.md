# 09: Unions

A union looks like a structure, but **all members share the same memory**. Its size equals its largest member, and only one member holds a meaningful value at a time.

```c
typedef union {
    int   i;
    float f;
    char  c[4];
} Data;

Data d;
d.i = 65;
printf("%c\n", d.c[0]);   // 'A' on a little-endian machine
d.f = 3.14f;              // overwrites d.i
```

## Key points

- `sizeof(union)` is the size of its largest member (plus any padding for alignment).
- Writing one member overwrites the others.
- Positional initialization sets only the **first** member. A designated initializer can set any: `Data e = {.f = 2.5f};`
- Reading a different member than the one last written reinterprets the bytes (type punning). C allows this through a union, but the result depends on byte order and representation. C++ does not allow it.
- Unions can contain structures, and structures can contain unions.

## Byte-level view of a float

```c
typedef union {
    float    f;
    uint8_t  bytes[4];
    uint32_t u32;
} FloatBytes;
```

For `1.0f`, `u32` is `0x3F800000`. On a little-endian machine, `bytes` are `00 00 80 3F` (least significant byte first). On a big-endian machine the order is reversed.

## Example

[`unions.c`](unions.c)

```
d.i = 65, d.c[0] = A
after d.f = 3.14f -> d.i = 1078523331 (0x4048F5C3)
sizeof(Data) = 4
1.0f as u32 = 0x3F800000
bytes in memory order: 00 00 80 3F
this machine is little-endian
e.f = 2.5
```

`d.i` after writing `3.14f` is just the bit pattern of that float read as an integer.

Previous: [08 Bit fields](../08-bit-fields/) | Next: [10 Structure vs union](../10-structure-vs-union/)
