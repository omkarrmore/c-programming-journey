#include <stdio.h>

enum Color { RED, GREEN, BLUE };                        /* 0, 1, 2          */
enum Level { LOW = 10, MEDIUM, HIGH = 50, CRITICAL };   /* 10, 11, 50, 51   */

typedef enum { OFF, ON } Power;                         /* typedef'd enum   */

/* a trailing COUNT entry is a handy way to loop over every value */
typedef enum { DAY_MON, DAY_TUE, DAY_WED, DAY_COUNT } Day;

int main(void)
{
    enum Color c = GREEN;
    Power p = ON;

    printf("RED=%d GREEN=%d BLUE=%d\n", RED, GREEN, BLUE);
    printf("LOW=%d MEDIUM=%d HIGH=%d CRITICAL=%d\n", LOW, MEDIUM, HIGH, CRITICAL);
    printf("c=%d, p=%d\n", c, p);

    c = BLUE;                       /* enumerators are just named integers */
    printf("c + 1 = %d\n", c + 1);

    for (Day d = DAY_MON; d < DAY_COUNT; d++)
        printf("day %d\n", d);

    return 0;
}
