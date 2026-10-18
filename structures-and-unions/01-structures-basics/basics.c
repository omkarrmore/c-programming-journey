#include <stdio.h>
#include <string.h>

typedef struct {
    int   id;
    char  name[20];
    float marks;
} Student;

int main(void)
{
    Student a = {1, "Amit", 78.5f};                        /* positional   */
    Student b = {.marks = 91.0f, .id = 2, .name = "Neha"}; /* designated   */
    Student c = {0};                                       /* all zeroed   */

    c.id = 3;
    strcpy(c.name, "Ravi");   /* arrays cannot be assigned with '=' */
    c.marks = 66.0f;

    Student d = a;            /* whole-structure copy */
    strcpy(d.name, "Copy");   /* changing the copy does not touch 'a' */

    printf("a: %d %s %.1f\n", a.id, a.name, a.marks);
    printf("b: %d %s %.1f\n", b.id, b.name, b.marks);
    printf("c: %d %s %.1f\n", c.id, c.name, c.marks);
    printf("d: %d %s %.1f\n", d.id, d.name, d.marks);
    printf("sizeof(Student) = %zu\n", sizeof(Student));
    return 0;
}
