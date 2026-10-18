#include <stdio.h>
#include <stdint.h>

typedef union {
    int   i;
    float f;
    char  c[4];
} Data;

typedef union {
    float    f;
    uint8_t  bytes[4];
    uint32_t u32;
} FloatBytes;

int main(void)
{
    Data d;
    d.i = 65;
    printf("d.i = %d, d.c[0] = %c\n", d.i, d.c[0]);

    d.f = 3.14f;                       /* overwrites d.i */
    printf("after d.f = 3.14f -> d.i = %d (0x%08X)\n", d.i, (unsigned)d.i);
    printf("sizeof(Data) = %zu\n", sizeof(Data));

    FloatBytes fb;
    fb.f = 1.0f;
    printf("1.0f as u32 = 0x%08X\n", (unsigned)fb.u32);
    printf("bytes in memory order: ");
    for (int i = 0; i < 4; i++)
        printf("%02X ", fb.bytes[i]);
    printf("\n");

    uint32_t one = 1;
    printf("this machine is %s-endian\n",
           *(uint8_t *)&one == 1 ? "little" : "big");

    Data e = {.f = 2.5f};              /* designated initializer */
    printf("e.f = %.1f\n", e.f);
    return 0;
}
