#include <stdio.h>

static size_t count_character(const char *text, char wanted)
{
    size_t count = 0;

    while (*text != '\0')
    {
        if (*text == wanted)
        {
            count++;
        }
        text++;
    }
    return count;
}

int main(void)
{
    const char *message = "Ready for departure";

    printf("e: %zu\n", count_character(message, 'e'));
    printf("R: %zu\n", count_character(message, 'R'));
    printf("z: %zu\n", count_character(message, 'z'));
    return 0;
}
