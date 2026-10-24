#include <stdio.h>

enum Color { RED, GREEN, BLUE };
enum Big   { SMALL = 1, HUGE = 1000000 };

int main(void)
{
    /* 1. an enum is stored as an integer type chosen by the compiler */
    printf("sizeof(enum Color) = %zu\n", sizeof(enum Color));
    printf("sizeof(enum Big)   = %zu\n", sizeof(enum Big));
    printf("sizeof(int)        = %zu\n", sizeof(int));

    /* 2. C does not stop you from storing a value that is not an enumerator */
    enum Color c = (enum Color)7;
    printf("c = %d (not RED, GREEN or BLUE!)\n", c);

    /* 3. enumerators are plain ints, so they mix freely with other numbers */
    int total = RED + GREEN + BLUE;
    printf("RED + GREEN + BLUE = %d\n", total);
    printf("BLUE == 2 ? %s\n", BLUE == 2 ? "yes" : "no");

    /* 4. different enum types compare without any complaint */
    enum Big b = SMALL;
    printf("GREEN == SMALL ? %s\n", GREEN == (int)b ? "yes" : "no");

    /* 5. validate before you trust a value that came from outside */
    int fromUart = 9;
    if (fromUart >= RED && fromUart <= BLUE)
        c = (enum Color)fromUart;
    else
        printf("rejected %d: not a valid Color\n", fromUart);
    return 0;
}
