#include <stdio.h>
#include <stddef.h>

struct A { char a; int b; char c; };
struct B { int b; char a; char c; };
struct __attribute__((packed)) P { char a; int b; char c; };  /* GCC/Clang */

int main(void)
{
    printf("sizeof(struct A) = %zu\n", sizeof(struct A));
    printf("  offset a=%zu b=%zu c=%zu\n",
           offsetof(struct A, a), offsetof(struct A, b), offsetof(struct A, c));

    printf("sizeof(struct B) = %zu\n", sizeof(struct B));
    printf("  offset b=%zu a=%zu c=%zu\n",
           offsetof(struct B, b), offsetof(struct B, a), offsetof(struct B, c));

    printf("sizeof(struct P) = %zu (packed)\n", sizeof(struct P));
    return 0;
}
