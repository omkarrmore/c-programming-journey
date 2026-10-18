#include <stdio.h>

struct Flags {
    unsigned int enable : 1;
    unsigned int mode   : 2;
    unsigned int speed  : 4;
};

int main(void)
{
    struct Flags f = {0};
    f.enable = 1;
    f.mode   = 3;
    f.speed  = 9;

    printf("enable=%u mode=%u speed=%u\n", f.enable, f.mode, f.speed);
    printf("sizeof(struct Flags) = %zu\n", sizeof(struct Flags));

    unsigned int big = 4;
    f.mode = big;   /* 4 does not fit in 2 bits: the stored value is truncated */
    printf("after f.mode = 4 -> mode=%u\n", f.mode);
    return 0;
}
