#include <stdio.h>

static void replace_spaces(char *text)
{
    while (*text != '\0')
    {
        if (*text == ' ')
        {
            *text = '_';
        }
        text++;
    }
}

int main(void)
{
    char title[] = "Guide entry";

    replace_spaces(title);
    puts(title);
    return 0;
}
