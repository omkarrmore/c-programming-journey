/*
 * 06_dynamic_memory.c
 * Topic : malloc / calloc / realloc / free, and the checks that go with them.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static void print_array(const char *label, const int *a, size_t n)
{
    printf("%s", label);
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    size_t n = 5;

    /* malloc: uninitialised memory. sizeof *a keeps it correct if the type changes */
    int *a = malloc(n * sizeof *a);
    if (a == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }
    for (size_t i = 0; i < n; i++)
        a[i] = (int)((i + 1) * (i + 1));          /* squares: 1 4 9 16 25 */
    print_array("malloc  (squares) : ", a, n);

    /* realloc: grow. Use a temporary so the old block isn't lost on failure */
    int *tmp = realloc(a, 2 * n * sizeof *a);
    if (tmp == NULL) {
        free(a);
        fprintf(stderr, "realloc failed\n");
        return 1;
    }
    a = tmp;
    for (size_t i = n; i < 2 * n; i++)
        a[i] = (int)((i + 1) * (i + 1));
    n *= 2;
    print_array("realloc (grown)   : ", a, n);

    free(a);
    a = NULL;                                      /* avoid a dangling pointer */

    /* calloc: zero-initialised */
    int *z = calloc(4, sizeof *z);
    if (z == NULL)
        return 1;
    print_array("calloc  (zeroed)  : ", z, 4);
    free(z);
    z = NULL;

    return 0;
}
