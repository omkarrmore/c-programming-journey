#include <stdio.h>

#define MAX 3

typedef struct {
    int   id;
    char  name[20];
    float marks;
} Student;

int main(void)
{
    Student cls[MAX] = {
        {1, "Amit", 78.5f},
        {2, "Neha", 91.0f},
        {3, "Ravi", 66.0f}
    };

    float total = 0;
    for (int i = 0; i < MAX; i++) {
        printf("%d  %-6s %.1f\n", cls[i].id, cls[i].name, cls[i].marks);
        total += cls[i].marks;
    }
    printf("Average = %.2f\n", total / MAX);
    printf("sizeof(cls) = %zu (= %d x %zu)\n", sizeof cls, MAX, sizeof(Student));
    return 0;
}
