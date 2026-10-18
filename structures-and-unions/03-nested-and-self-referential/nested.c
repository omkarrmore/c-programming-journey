#include <stdio.h>

/* ---- nested structure ---- */
typedef struct {
    int day, month, year;
} Date;

typedef struct {
    int  id;
    char name[20];
    Date joined;
} Employee;

/* ---- self-referential structure ---- */
typedef struct Node {
    int data;
    struct Node *next;   /* pointer to its own type */
} Node;

int main(void)
{
    Employee e = {101, "Omkar", {1, 6, 2026}};
    printf("%d %s joined %02d-%02d-%d\n",
           e.id, e.name, e.joined.day, e.joined.month, e.joined.year);

    /* a tiny linked list built from three nodes: 10 -> 20 -> 30 */
    Node n3 = {30, NULL};
    Node n2 = {20, &n3};
    Node n1 = {10, &n2};

    for (Node *p = &n1; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
    return 0;
}
