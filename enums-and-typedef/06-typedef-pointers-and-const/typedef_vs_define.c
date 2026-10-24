#include <stdio.h>

typedef int *IntPtr;        /* a real type: "pointer to int"              */
#define INTPTR int *        /* just text, replaced before parsing         */

int main(void)
{
    /* ---- 1. declaring two variables ---- */
    IntPtr a, b;            /* both are int *                              */
    INTPTR c, d;            /* expands to: int * c, d;  -> d is a plain int */

    printf("sizeof(a)=%zu sizeof(b)=%zu\n", sizeof a, sizeof b);
    printf("sizeof(c)=%zu sizeof(d)=%zu\n", sizeof c, sizeof d);

    /* ---- 2. const binds differently ---- */
    int x = 1, y = 2;

    const IntPtr p1 = &x;   /* const applies to the TYPE IntPtr: int *const p1 */
    *p1 = 10;               /* OK: the int can change                          */
    /* p1 = &y;                ERROR: p1 itself is const                       */

    const INTPTR p2 = &x;   /* expands to: const int * p2 (pointer to const)   */
    p2 = &y;                /* OK: the pointer can move                        */
    /* *p2 = 20;               ERROR: the int is read-only through p2          */

    printf("x=%d *p1=%d *p2=%d\n", x, *p1, *p2);

    (void)a; (void)b; (void)c; (void)d;
    return 0;
}
