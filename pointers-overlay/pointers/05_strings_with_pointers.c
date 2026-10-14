/*
 * 05_strings_with_pointers.c
 * Topic : Strings are char arrays ending in '\0'. Pointer-based versions of
 *         strlen, strcpy, reverse and word-by-word in-place reversal.
 */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

static size_t my_strlen(const char *s)
{
    const char *p = s;
    while (*p)
        p++;
    return (size_t)(p - s);
}

static void my_strcpy(char *dst, const char *src)
{
    while ((*dst++ = *src++))
        ;                             /* copies '\0' too, then stops */
}

/* Reverse the characters in [start, end] in place */
static void reverse_range(char *start, char *end)
{
    while (start < end) {             /* half the length, not the full length */
        char t = *start;
        *start++ = *end;
        *end-- = t;
    }
}

static void reverse_string(char *s)
{
    size_t n = my_strlen(s);
    if (n > 1)
        reverse_range(s, s + n - 1);
}

static int count_vowels(const char *s)
{
    int count = 0;
    for (; *s; s++) {
        switch (*s) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            count++;
        }
    }
    return count;
}

/* Split on spaces by hand and reverse each word in place */
static void reverse_each_word(char *line)
{
    char *p = line;
    while (*p) {
        while (*p == ' ')
            p++;
        if (!*p)
            break;
        char *start = p;
        while (*p && *p != ' ')
            p++;
        reverse_range(start, p - 1);
    }
}

int main(void)
{
    char s[] = "pointers";
    printf("my_strlen(\"%s\") = %zu\n", s, my_strlen(s));

    reverse_string(s);
    printf("reversed         = %s\n", s);

    char copy[32];
    my_strcpy(copy, "embedded C");
    printf("my_strcpy        = %s\n", copy);
    printf("vowels in \"%s\" = %d\n", copy, count_vowels(copy));

    char line[128];
    printf("\nEnter a sentence: ");
    if (fgets(line, sizeof line, stdin) == NULL)
        strcpy(line, "hello embedded world\n");
    line[strcspn(line, "\n")] = '\0'; /* strip the newline left by fgets */

    reverse_each_word(line);
    printf("Each word reversed: %s\n", line);

    return 0;
}
