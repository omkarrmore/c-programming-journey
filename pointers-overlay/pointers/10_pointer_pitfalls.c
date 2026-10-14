/*
 * 10_pointer_pitfalls.c
 * Topic : The classic pointer bugs, and the safe pattern for each.
 *         The unsafe versions are only shown in comments.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Wrapped in do { ... } while (0) so the macro behaves like ONE statement,
 * e.g. inside an unbraced if/else.
 */
#define SAFE_FREE(p) do { free(p); (p) = NULL; } while (0)

/* 1. Dangling pointer: returning the address of a local variable
 *      char *bad(void) { char buf[16] = "hi"; return buf; }   // buf dies on return
 *    Safe: allocate on the heap and let the caller free it. */
static char *make_greeting(const char *name)
{
    size_t len = strlen("Hello, ") + strlen(name) + 1;
    char *s = malloc(len);
    if (s == NULL)
        return NULL;
    snprintf(s, len, "Hello, %s", name);
    return s;
}

/* 2. Buffer overrun: always bound your copies. */
static void safe_copy(char *dst, size_t dst_size, const char *src)
{
    snprintf(dst, dst_size, "%s", src);   /* truncates instead of overflowing */
}

int main(void)
{
    /* 1 */
    char *g = make_greeting("Omkar");
    if (g != NULL) {
        printf("%s\n", g);
        SAFE_FREE(g);
    }

    /* 2. Use-after-free: after SAFE_FREE, g is NULL, so a stray *g is a
     *    clean, testable state instead of silent memory corruption. */
    if (g == NULL)
        printf("g is NULL after free -> safe to test, impossible to misuse\n");

    /* 3. Overrun */
    char small[8];
    safe_copy(small, sizeof small, "this string is too long");
    printf("Truncated safely: \"%s\"\n", small);

    /* 4. Uninitialised pointer: int *p; *p = 5;   // writes to a random address
     *    Safe: initialise to NULL or a valid address, and check before use. */
    int *p = NULL;
    if (p == NULL)
        printf("Initialised to NULL, checked before use\n");

    /* 5. sizeof on a pointer is not the array size */
    int arr[10];
    int *q = arr;
    printf("sizeof(arr) = %zu, sizeof(q) = %zu\n", sizeof arr, sizeof q);

    /* 6. fgets keeps the newline: strip it before comparing or printing */
    char line[16] = "text\n";
    line[strcspn(line, "\n")] = '\0';
    printf("After stripping newline: \"%s\"\n", line);

    return 0;
}
