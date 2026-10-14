/*
 * 03_pointers_and_arrays.c
 * Topic : arr[i] == *(arr + i). Arrays "decay" to a pointer to their
 *         first element when passed to a function.
 */
#include <stdio.h>
#include <stddef.h>

static void show_size_in_function(const int *a)
{
    /* Inside a function, 'a' is just a pointer: sizeof gives pointer size */
    printf("Inside function : sizeof(a) = %zu (pointer size, NOT array size)\n",
           sizeof a);
}

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;                     /* same as &arr[0] */

    for (size_t i = 0; i < 5; i++) {
        printf("arr[%zu]=%d  *(arr+%zu)=%d  p[%zu]=%d  *(p+%zu)=%d\n",
               i, arr[i], i, *(arr + i), i, p[i], i, *(p + i));
    }

    printf("\nIn main         : sizeof(arr) = %zu bytes (whole array)\n", sizeof arr);
    printf("In main         : sizeof(p)   = %zu bytes (just a pointer)\n", sizeof p);
    show_size_in_function(arr);

    printf("\n&arr[0] = %p\narr     = %p   <- same address\n",
           (void *)&arr[0], (void *)arr);

    return 0;
}
