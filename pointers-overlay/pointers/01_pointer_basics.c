/*
 * 01_pointer_basics.c
 * Topic : What a pointer is, & (address-of) and * (dereference)
 * Build : gcc -std=c11 -Wall -Wextra -Wpedantic 01_pointer_basics.c -o 01
 */
#include <stdio.h>

int main(void)
{
    int x = 10;
    int *p = &x;                      /* p stores the ADDRESS of x */

    printf("Value of x            : %d\n", x);
    printf("Address of x   (&x)   : %p\n", (void *)&x);
    printf("Value of p     (p)    : %p   <- same as &x\n", (void *)p);
    printf("Value at p     (*p)   : %d\n", *p);
    printf("Address of p   (&p)   : %p   <- a pointer is a variable too\n", (void *)&p);
    printf("sizeof(p)             : %zu bytes\n", sizeof p);

    *p = 25;                          /* write through the pointer */
    printf("\nAfter *p = 25  ->  x = %d\n", x);

    /* A pointer with no valid target should be NULL, never left uninitialised */
    int *np = NULL;
    if (np == NULL)
        printf("np is NULL -> never dereference it\n");

    return 0;
}
