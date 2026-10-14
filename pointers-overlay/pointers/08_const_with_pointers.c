/*
 * 08_const_with_pointers.c
 * Topic : Read declarations RIGHT TO LEFT.
 *   const int *p        -> p is a pointer to a const int   (data read-only)
 *   int *const p        -> p is a const pointer to an int  (pointer fixed)
 *   const int *const p  -> both fixed
 */
#include <stdio.h>

int main(void)
{
    int a = 1, b = 2;

    const int *p1 = &a;               /* data read-only, pointer can move */
    /* *p1 = 5;  ERROR: assignment of read-only location */
    p1 = &b;
    printf("p1 now sees b = %d\n", *p1);

    int *const p2 = &a;               /* pointer fixed, data writable */
    *p2 = 10;
    /* p2 = &b;  ERROR: assignment of read-only variable 'p2' */
    printf("a changed through p2 = %d\n", a);

    const int *const p3 = &a;         /* nothing can change through p3 */
    /* *p3 = 3;  ERROR     p3 = &b;  ERROR */
    printf("p3 reads a = %d\n", *p3);

    /* Why it matters: const in a parameter promises "I will not modify this" */
    return 0;
}
