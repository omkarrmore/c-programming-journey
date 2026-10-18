#include <stdio.h>

typedef struct {
    int   id;
    char  name[20];
    float marks;
} Student;

typedef struct {
    int x, y;
} Point;

void byValue(Student s)
{
    s.marks = 0;                                  /* changes a COPY */
    printf("inside byValue: %.1f\n", s.marks);
}
void byPointer(Student *s)  { s->marks = 0; }   /* changes the ORIGINAL */
void show(const Student *s) { printf("%s: %.1f\n", s->name, s->marks); }

/* returning a small structure by value is fine */
Point makePoint(int x, int y)
{
    Point p = {x, y};
    return p;
}

int main(void)
{
    Student s = {1, "Amit", 78.5f};

    byValue(s);
    show(&s);              /* still 78.5 */

    byPointer(&s);
    show(&s);              /* now 0.0    */

    Point p = makePoint(3, 4);
    printf("Point: (%d, %d)\n", p.x, p.y);
    return 0;
}
