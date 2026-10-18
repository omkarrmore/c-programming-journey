#include <stdio.h>
#include <string.h>

typedef struct {
    int   id;
    char  name[20];
    float marks;
} Student;

/* Q6: sort in place, highest marks first (bubble sort) */
void sortByMarks(Student *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j].marks < arr[j + 1].marks) {
                Student tmp = arr[j];
                arr[j]      = arr[j + 1];
                arr[j + 1]  = tmp;
            }
}

/* Q7: tagged union holding an int or a 4-character string */
typedef enum { K_INT, K_STR } Kind;

typedef struct {
    Kind kind;
    union {
        int  i;
        char s[5];          /* 4 characters + '\0' */
    } u;
} Item;

void printItem(const Item *it)
{
    if (it->kind == K_INT)
        printf("int: %d\n", it->u.i);
    else
        printf("str: %s\n", it->u.s);
}

/* Q4 check */
struct A { char a; int b; char c; };
struct B { int b; char a; char c; };

int main(void)
{
    Student cls[3] = {
        {1, "Amit", 78.5f},
        {2, "Neha", 91.0f},
        {3, "Ravi", 66.0f}
    };
    sortByMarks(cls, 3);
    for (int i = 0; i < 3; i++)
        printf("%d %-5s %.1f\n", cls[i].id, cls[i].name, cls[i].marks);

    Item x = {K_INT, {.i = 7}};
    Item y; y.kind = K_STR; strcpy(y.u.s, "ABCD");
    printItem(&x);
    printItem(&y);

    printf("sizeof(struct A) = %zu, sizeof(struct B) = %zu\n",
           sizeof(struct A), sizeof(struct B));
    return 0;
}
