# 08: Bit fields

Bit fields pack small values into a fixed number of bits inside a structure.

```c
struct Flags {
    unsigned int enable : 1;
    unsigned int mode   : 2;
    unsigned int speed  : 4;
};
```

## Key points

- Useful for hardware registers and compact flags.
- The order of bits within a byte and the packing of fields are **implementation-defined**, so layouts are not portable across compilers. Check your compiler's documentation before mapping a bit field onto a real register.
- You cannot take the address of a bit field.
- A value too large for the field is truncated. `mode` is 2 bits, so storing 4 gives 0.
- `sizeof` is at least the size of the underlying type (here 4 bytes for `unsigned int`), even though only 7 bits are used.

## Example

[`bitfields.c`](bitfields.c)

```
enable=1 mode=3 speed=9
sizeof(struct Flags) = 4
after f.mode = 4 -> mode=0
```

Previous: [07 Padding and alignment](../07-padding-and-alignment/) | Next: [09 Unions](../09-unions/)
