#include <stdio.h>

/* without typedef:  int (*op)(int, int)
   with typedef:     BinaryOp op                                   */
typedef int (*BinaryOp)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

/* a lookup table of name + function */
typedef struct {
    const char *name;
    BinaryOp    fn;
} Operation;

/* callback pattern: the caller decides what happens on the event */
typedef void (*Callback)(int value);

static void onHigh(int v) { printf("  callback: %d is HIGH\n", v); }
static void onLow(int v)  { printf("  callback: %d is low\n", v); }

static void check(int value, int threshold, Callback high, Callback low)
{
    if (value > threshold) high(value);
    else                   low(value);
}

int main(void)
{
    Operation table[] = {
        {"add", add},
        {"sub", sub},
        {"mul", mul}
    };

    for (unsigned i = 0; i < sizeof table / sizeof table[0]; i++)
        printf("%s(6, 3) = %d\n", table[i].name, table[i].fn(6, 3));

    BinaryOp op = mul;              /* pick a function at run time */
    printf("op(4, 5) = %d\n", op(4, 5));

    check(80, 50, onHigh, onLow);
    check(20, 50, onHigh, onLow);
    return 0;
}
