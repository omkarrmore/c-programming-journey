/*
 * 04_pointer_arithmetic.c
 * Topic : p + 1 moves by sizeof(*p) bytes, not by 1 byte.
 */
#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("p       = %p\n", (void *)p);
    printf("p + 1   = %p\n", (void *)(p + 1));
    printf("Step in bytes = %td (sizeof(int) = %zu)\n",
           (char *)(p + 1) - (char *)p, sizeof(int));

    char text[] = "ABCDE";
    char *cp = text;
    printf("\ncp + 1 moves %td byte(s); *(cp + 1) = %c\n",
           (char *)(cp + 1) - (char *)cp, *(cp + 1));

    /* Pointer difference gives the number of ELEMENTS between two pointers */
    int *end = &arr[4];
    ptrdiff_t gap = end - p;
    printf("\n&arr[4] - &arr[0] = %td elements\n", gap);

    /* Traversing with a pointer */
    printf("\nTraverse: ");
    for (int *q = arr; q < arr + 5; q++)
        printf("%d ", *q);
    printf("\n");

    /* Summing with a pointer */
    int sum = 0;
    for (const int *q = arr; q != arr + 5; q++)
        sum += *q;
    printf("Sum = %d\n", sum);

    /* Precedence: *q++ vs (*q)++ */
    int vals[3] = {1, 2, 3};
    int *q = vals;
    int v = *q++;                     /* read value, THEN move pointer */
    printf("\n*q++   -> value read = %d, q now points at vals[%td] (=%d)\n",
           v, q - vals, *q);
    (*q)++;                           /* increment the VALUE, pointer stays */
    printf("(*q)++  -> vals[1] is now %d, q still at vals[%td]\n", vals[1], q - vals);

    return 0;
}
