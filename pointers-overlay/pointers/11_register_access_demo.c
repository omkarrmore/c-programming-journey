/*
 * 11_register_access_demo.c
 * Topic : Why pointers matter in embedded C.
 *
 * On a microcontroller a peripheral register is just a memory address, e.g. on
 * STM32F4 the GPIOA output data register (ODR) lives at 0x40020014:
 *
 *     #define GPIOA_ODR (*(volatile uint32_t *)0x40020014)
 *     GPIOA_ODR |= (1U << 5);          // set pin PA5
 *
 * That address does not exist on a PC, so this demo uses a plain variable as a
 * stand-in register. The pointer technique is exactly the same.
 */
#include <stdio.h>
#include <stdint.h>

static uint32_t fake_odr = 0;                       /* pretend hardware register */
#define ODR (*(volatile uint32_t *)&fake_odr)

#define SET_BIT(reg, n)    ((reg) |=  (1U << (n)))
#define CLEAR_BIT(reg, n)  ((reg) &= ~(1U << (n)))
#define TOGGLE_BIT(reg, n) ((reg) ^=  (1U << (n)))
#define READ_BIT(reg, n)   (((reg) >> (n)) & 1U)

static void print_bits(const char *label, uint32_t v)
{
    printf("%-14s: 0x%08X  (bit5=%u, bit7=%u)\n",
           label, (unsigned)v, (unsigned)READ_BIT(v, 5), (unsigned)READ_BIT(v, 7));
}

int main(void)
{
    print_bits("reset", ODR);

    SET_BIT(ODR, 5);
    print_bits("set bit 5", ODR);

    SET_BIT(ODR, 7);
    print_bits("set bit 7", ODR);

    CLEAR_BIT(ODR, 5);
    print_bits("clear bit 5", ODR);

    TOGGLE_BIT(ODR, 5);
    print_bits("toggle bit 5", ODR);

    return 0;
}
