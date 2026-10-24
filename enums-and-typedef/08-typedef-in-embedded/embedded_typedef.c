#include <stdio.h>
#include <stdint.h>

/* ---- fixed-width types: sizes are guaranteed ---- */
typedef uint16_t millivolt_t;           /* a typedef can also document units */
typedef uint8_t  pin_t;

/* ---- register access ---- */
typedef volatile uint32_t reg32;        /* volatile: the hardware can change it */

typedef struct {
    reg32 CTRL;
    reg32 STATUS;
    reg32 DATA;
} UART_TypeDef;

#define BIT(n)        (1u << (n))
#define UART_EN       BIT(0)
#define UART_TX_READY BIT(1)

/* On a real MCU this would be a fixed address, e.g.
       #define UART0 ((UART_TypeDef *)0x40001000u)
   Here a plain variable stands in for the hardware so the code can run on a PC. */
static UART_TypeDef fakeUart;
#define UART0 (&fakeUart)

static void uartInit(UART_TypeDef *u)
{
    u->CTRL |= UART_EN;                 /* set a bit    */
    u->STATUS |= UART_TX_READY;
}

static void uartSend(UART_TypeDef *u, uint8_t byte)
{
    if (u->STATUS & UART_TX_READY)      /* test a bit   */
        u->DATA = byte;
}

int main(void)
{
    millivolt_t vbat = 3300;
    pin_t led = 13;
    printf("vbat=%u mV, led pin=%u\n", vbat, led);
    printf("sizeof: uint8_t=%zu uint16_t=%zu uint32_t=%zu\n",
           sizeof(uint8_t), sizeof(uint16_t), sizeof(uint32_t));

    uartInit(UART0);
    uartSend(UART0, 'A');
    printf("CTRL=0x%X STATUS=0x%X DATA=0x%X ('%c')\n",
           (unsigned)UART0->CTRL, (unsigned)UART0->STATUS,
           (unsigned)UART0->DATA, (char)UART0->DATA);

    UART0->CTRL &= ~UART_EN;            /* clear a bit  */
    printf("after clearing EN: CTRL=0x%X\n", (unsigned)UART0->CTRL);
    return 0;
}
