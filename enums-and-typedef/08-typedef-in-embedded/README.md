# 08: typedef in embedded code

Embedded code uses `typedef` constantly. Three patterns cover most of it.

## 1. Fixed-width types

`int` and `long` change size between targets. The types in `<stdint.h>` do not.

```c
#include <stdint.h>

uint8_t  a;    // always 8 bits
uint16_t b;    // always 16 bits
uint32_t c;    // always 32 bits
```

You can add your own aliases to document meaning:

```c
typedef uint16_t millivolt_t;
typedef uint8_t  pin_t;
```

## 2. Register types

```c
typedef volatile uint32_t reg32;

typedef struct {
    reg32 CTRL;
    reg32 STATUS;
    reg32 DATA;
} UART_TypeDef;

#define UART0 ((UART_TypeDef *)0x40001000u)   // fixed hardware address
```

- `volatile` tells the compiler the hardware can change the value at any time, so it must not optimize reads and writes away.
- Overlaying a structure on a fixed address gives names to the registers (`UART0->CTRL`). Vendor headers (CMSIS and similar) are built this way.
- In the example a normal variable stands in for the hardware so the program can run on a PC.

## 3. Bit macros

```c
#define BIT(n)        (1u << (n))
#define UART_EN       BIT(0)
#define UART_TX_READY BIT(1)

u->CTRL |=  UART_EN;          // set a bit
if (u->STATUS & UART_TX_READY) // test a bit
u->CTRL &= ~UART_EN;          // clear a bit
```

Note the parentheses in the macro: they prevent the text-substitution trap from topic 02.

## Key points

- Use `<stdint.h>` types for anything that touches hardware, memory layouts or protocols.
- Mark hardware registers `volatile`.
- Structure layout on a register block depends on **padding**: use fixed-width members so the offsets match the datasheet (see the Structures and Unions notes).
- Typedefs for units and pins make code easier to read and review.

## Example

[`embedded_typedef.c`](embedded_typedef.c)

```
vbat=3300 mV, led pin=13
sizeof: uint8_t=1 uint16_t=2 uint32_t=4
CTRL=0x1 STATUS=0x2 DATA=0x41 ('A')
after clearing EN: CTRL=0x0
```

Previous: [07 typedef for function pointers](../07-typedef-function-pointers/) | Next: [09 Tagged union revisited](../09-tagged-union-revisited/)
