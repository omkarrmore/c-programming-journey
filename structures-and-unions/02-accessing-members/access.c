#include <stdio.h>

typedef struct {
    int   id;
    char  name[20];
    float marks;
} Student;

int main(void)
{
    Student s1 = {1, "Amit", 78.5f};
    Student *p = &s1;

    printf("s1.name     = %s\n", s1.name);     /* dot on a variable   */
    printf("p->name     = %s\n", p->name);     /* arrow on a pointer  */
    printf("(*p).name   = %s\n", (*p).name);   /* same as p->name     */

    p->marks += 5.0f;                          /* modify through pointer */
    printf("s1.marks    = %.1f\n", s1.marks);
    return 0;
}
