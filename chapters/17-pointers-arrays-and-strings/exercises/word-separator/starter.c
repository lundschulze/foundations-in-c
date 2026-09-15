#include <stdio.h>

static void replace_underscores(char *text)
{
    /* TODO: replace every underscore with a space. */
    (void)text;
}

int main(void)
{
    char title[] = "Mostly_harmless";

    replace_underscores(title);
    puts(title);
    return 0;
}
