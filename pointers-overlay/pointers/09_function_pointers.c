/*
 * 09_function_pointers.c
 * Topic : Pointers to functions: dispatch tables, callbacks, qsort.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int (*binary_op)(int, int);

static int add(int a, int b) { return a + b; }
static int sub(int a, int b) { return a - b; }
static int mul(int a, int b) { return a * b; }

static int apply(binary_op op, int a, int b)
{
    return op(a, b);                  /* the call goes through the pointer */
}

/* Callback: for_each calls fn on every element */
static void for_each(const int *arr, size_t n, void (*fn)(int))
{
    for (size_t i = 0; i < n; i++)
        fn(arr[i]);
}

static void print_item(int v) { printf("[%d] ", v); }

static int cmp_int_asc(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);         /* avoids overflow from x - y */
}

int main(void)
{
    binary_op op = add;
    printf("op = add -> %d\n", op(6, 3));

    /* Dispatch table: pick behaviour by index at runtime */
    binary_op table[] = {add, sub, mul};
    const char *names[] = {"add", "sub", "mul"};
    for (size_t i = 0; i < 3; i++)
        printf("%s(8, 4) = %d\n", names[i], apply(table[i], 8, 4));

    int data[] = {42, 7, 99, -3, 18};
    size_t n = sizeof data / sizeof data[0];

    printf("\nCallback : ");
    for_each(data, n, print_item);

    qsort(data, n, sizeof data[0], cmp_int_asc);
    printf("\nqsort    : ");
    for_each(data, n, print_item);
    printf("\n");

    return 0;
}
