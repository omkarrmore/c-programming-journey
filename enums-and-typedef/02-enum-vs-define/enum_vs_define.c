#include <stdio.h>

/* ---- 1. the classic macro trap: text substitution ---- */
#define SIZE_DEF 2 + 3              /* expands to the raw text 2 + 3     */
enum { SIZE_ENUM = 2 + 3 };         /* evaluated once, value is 5        */

/* ---- 2. #define groups nothing, enum groups related names ---- */
#define MODE_IDLE 0
#define MODE_RUN  1
enum Mode { M_IDLE, M_RUN };

/* ---- 3. enum constants are real constant expressions ---- */
enum { BUF_LEN = 4 };

int main(void)
{
    printf("SIZE_DEF  * 2 = %d  (2 + 3 * 2)\n", SIZE_DEF * 2);
    printf("SIZE_ENUM * 2 = %d\n", SIZE_ENUM * 2);

    enum Mode m = M_RUN;            /* a variable of the enum type        */
    int legacy  = MODE_RUN;         /* just an int, no type information   */
    printf("m=%d legacy=%d\n", m, legacy);

    int buf[BUF_LEN] = {0};         /* usable as an array size            */
    printf("buf has %zu elements\n", sizeof buf / sizeof buf[0]);

    {
        enum { LOCAL = 7 };         /* enum constants obey block scope    */
        printf("LOCAL = %d\n", LOCAL);
    }
#define LATER 99                    /* a macro ignores scope entirely     */
    printf("LATER = %d\n", LATER);
    return 0;
}
