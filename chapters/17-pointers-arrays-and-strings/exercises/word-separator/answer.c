#include <stdio.h>

static void replace_underscores(char *text)
{
    while (*text != '\0')
    {
        if (*text == '_')
        {
            *text = ' ';
        }
        text++;
    }
}

int main(void)
{
    char title[] = "Ready_for_departure";
    char empty[] = "";
    char unchanged[] = "Bag";

    replace_underscores(title);
    replace_underscores(empty);
    replace_underscores(unchanged);
    puts(title);
    puts(empty);
    puts(unchanged);
    return 0;
}
