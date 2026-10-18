#include <stdio.h>
#include <stdint.h>

/* a) register accessed as a whole byte or by field */
typedef union {
    uint8_t reg;
    struct {
        uint8_t enable : 1;
        uint8_t mode   : 2;
        uint8_t        : 1;     /* unused bit */
        uint8_t speed  : 4;
    } bits;
} Ctrl;

/* b) float <-> bytes for UART/SPI */
typedef union {
    float   f;
    uint8_t bytes[4];
} FloatBytes;

/* c) tagged union: one of several possible values */
typedef enum { T_INT, T_FLOAT } Type;

typedef struct {
    Type type;
    union {
        int   i;
        float f;
    } v;
} Value;

static void printValue(const Value *v)
{
    if (v->type == T_INT)
        printf("int   %d\n", v->v.i);
    else
        printf("float %.2f\n", v->v.f);
}

int main(void)
{
    /* a) */
    Ctrl c;
    c.reg = 0;
    c.bits.enable = 1;
    c.bits.mode   = 2;
    c.bits.speed  = 5;
    printf("reg = 0x%02X, sizeof(Ctrl) = %zu\n", c.reg, sizeof(Ctrl));

    /* b) sender splits the float, receiver rebuilds it */
    FloatBytes tx, rx;
    tx.f = 36.6f;
    uint8_t frame[4];
    for (int i = 0; i < 4; i++)
        frame[i] = tx.bytes[i];            /* "send" over UART */
    for (int i = 0; i < 4; i++)
        rx.bytes[i] = frame[i];            /* "receive"        */
    printf("sent %.1f, received %.1f\n", tx.f, rx.f);

    /* c) */
    Value a = {T_INT,   {.i = 42}};
    Value b = {T_FLOAT, {.f = 3.5f}};
    printValue(&a);
    printValue(&b);
    return 0;
}
