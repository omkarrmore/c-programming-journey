#include <stdio.h>

typedef unsigned int uint;              /* alias for a basic type            */
typedef unsigned char byte;

typedef struct {                        /* alias for an anonymous struct     */
    int x, y;
} Point;

typedef struct Node {                   /* self-referential: keep the tag    */
    int data;
    struct Node *next;
} Node;

typedef int Row[3];                     /* alias for an array type           */

int main(void)
{
    uint u = 4000000000u;
    byte b = 255;
    Point p = {3, 4};
    Node n2 = {20, NULL};
    Node n1 = {10, &n2};
    Row r = {1, 2, 3};

    printf("u=%u b=%u\n", u, b);
    printf("p=(%d, %d)\n", p.x, p.y);
    printf("n1.next->data = %d\n", n1.next->data);
    printf("r has %zu ints, sizeof(Row)=%zu\n", sizeof r / sizeof r[0], sizeof(Row));
    return 0;
}
