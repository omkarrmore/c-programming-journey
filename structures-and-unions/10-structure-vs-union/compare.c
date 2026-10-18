#include <stdio.h>

struct S { int i; float f; char c[4]; };
union  U { int i; float f; char c[4]; };

int main(void)
{
    struct S s;
    union  U u;

    printf("sizeof(struct S) = %zu\n", sizeof s);
    printf("sizeof(union  U) = %zu\n", sizeof u);

    printf("struct: &s.i == &s.f ? %s\n", (void *)&s.i == (void *)&s.f ? "yes" : "no");
    printf("union : &u.i == &u.f ? %s\n", (void *)&u.i == (void *)&u.f ? "yes" : "no");
    return 0;
}
