#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

typedef struct {
    int   id;
    char  name[20];
    float marks;
} Student;

/* read-only access: 'const' stops the function from modifying the data */
void printStudents(const Student *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  %-8s %.1f\n", (arr + i)->id, (arr + i)->name, (arr + i)->marks);
}

/* modifies the caller's array directly */
void addGrace(Student *arr, int n, float grace)
{
    for (int i = 0; i < n; i++)
        arr[i].marks += grace;
}

/* returns a pointer to an element INSIDE the caller's array */
Student *findTopper(Student *arr, int n)
{
    Student *top = arr;
    for (Student *p = arr + 1; p < arr + n; p++)
        if (p->marks > top->marks)
            top = p;
    return top;
}

int main(void)
{
    Student cls[MAX] = {
        {1, "Amit", 78.5f},
        {2, "Neha", 91.0f},
        {3, "Ravi", 66.0f}
    };

    /* pointer to the first element */
    Student *p = cls;
    printf("First:  %s\n", p->name);
    printf("Second: %s\n", (p + 1)->name);

    addGrace(cls, MAX, 2.0f);
    printStudents(cls, MAX);

    Student *top = findTopper(cls, MAX);
    printf("Topper: %s (%.1f)\n", top->name, top->marks);

    /* pointer to the WHOLE array */
    Student (*pa)[MAX] = &cls;
    printf("Via pointer to array: %s\n", (*pa)[2].name);
    printf("p + 1  moves %td bytes\n", (char *)(p + 1)  - (char *)p);
    printf("pa + 1 moves %td bytes\n", (char *)(pa + 1) - (char *)pa);

    /* dynamic array: the same functions work unchanged */
    int n = 2;
    Student *list = malloc(n * sizeof(Student));
    if (list == NULL)
        return 1;
    list[0] = (Student){10, "Dyn1", 50.0f};
    list[1] = (Student){11, "Dyn2", 60.0f};
    addGrace(list, n, 5.0f);
    printStudents(list, n);
    free(list);
    return 0;
}
