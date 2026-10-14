/*
 * 02_call_by_reference.c
 * Topic : C passes everything by value. Pointers let a function change
 *         the caller's variables ("call by reference").
 */
#include <stdio.h>
#include <stddef.h>

static void swap_wrong(int a, int b)      /* swaps COPIES only */
{
    int t = a;
    a = b;
    b = t;
}

static void swap(int *a, int *b)          /* swaps the ORIGINALS */
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* Returning more than one value: use output parameters */
static void min_max(const int *arr, size_t n, int *min, int *max)
{
    *min = *max = arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main(void)
{
    int a = 5, b = 9;

    swap_wrong(a, b);
    printf("After swap_wrong : a=%d b=%d  (unchanged)\n", a, b);

    swap(&a, &b);
    printf("After swap       : a=%d b=%d  (swapped)\n", a, b);

    int data[] = {42, 7, 99, -3, 18};
    int lo, hi;
    min_max(data, sizeof data / sizeof data[0], &lo, &hi);
    printf("min=%d max=%d\n", lo, hi);

    return 0;
}
