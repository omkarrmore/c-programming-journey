/*
 * 07_pointer_to_pointer.c
 * Topic : int **pp. Needed when a function must change the POINTER itself.
 */
#include <stdio.h>
#include <stdlib.h>

/* The function gets the address of the caller's pointer, so it can set it */
static int allocate_int(int **out, int value)
{
    *out = malloc(sizeof **out);
    if (*out == NULL)
        return -1;
    **out = value;
    return 0;
}

int main(void)
{
    int x = 5, y = 50;
    int *p = &x;
    int **pp = &p;

    printf("x = %d, *p = %d, **pp = %d\n", x, *p, **pp);

    **pp = 7;                         /* changes x */
    printf("After **pp = 7  -> x = %d\n", x);

    *pp = &y;                         /* changes WHERE p points */
    printf("After *pp = &y  -> *p = %d (p now points to y)\n", *p);

    int *heap = NULL;
    if (allocate_int(&heap, 99) == 0) {
        printf("allocate_int set heap -> %d\n", *heap);
        free(heap);
    }

    /* An array of strings is an array of pointers; its name decays to char ** */
    const char *names[] = {"STM32", "PIC16F877A", "FreeRTOS"};
    const char **pn = names;
    for (int i = 0; i < 3; i++)
        printf("pn[%d] = %s\n", i, *(pn + i));

    return 0;
}
