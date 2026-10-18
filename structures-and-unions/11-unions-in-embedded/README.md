# 11: Unions in embedded work

## a) Register accessed as a whole or by field

```c
typedef union {
    uint8_t reg;
    struct {
        uint8_t enable : 1;
        uint8_t mode   : 2;
        uint8_t        : 1;     // unused bit
        uint8_t speed  : 4;
    } bits;
} Ctrl;

Ctrl c;
c.reg = 0;
c.bits.enable = 1;
c.bits.mode   = 2;
c.bits.speed  = 5;
// c.reg == 0x55 with GCC on a little-endian target
```

Bit-field order is implementation-defined, so verify the layout for your compiler and target before relying on it with real hardware registers.

## b) Sending a float over UART or SPI

Put the float and a `uint8_t[4]` array in a union. The sender transmits `bytes[0..3]`, and the receiver rebuilds the float the same way. Both sides must agree on byte order (and both must use the same float format).

## c) Variant data with a type tag (tagged union)

Only one union member is valid at a time, so store which one in a separate field.

```c
typedef enum { T_INT, T_FLOAT } Type;

typedef struct {
    Type type;
    union { int i; float f; } v;
} Value;
```

This is a safe way to hold "one of several possible values", for example different sensor readings in one queue.

## Key points

- Always check the tag before reading a union member.
- Fixed-width types (`uint8_t`, `uint32_t`) make layouts predictable.
- Document the byte order whenever a union crosses a communication link.

## Example

[`embedded_unions.c`](embedded_unions.c)

```
reg = 0x55, sizeof(Ctrl) = 1
sent 36.6, received 36.6
int   42
float 3.50
```

Previous: [10 Structure vs union](../10-structure-vs-union/) | Next: [12 Common mistakes](../12-common-mistakes/)
