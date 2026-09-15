#include <stdio.h>

int main(void)
{
    char name[] = "maya";

    if (name[0] >= 'a' && name[0] <= 'z')
    {
        name[0] = name[0] - 'a' + 'A';
    }

    puts(name);
    return 0;
}

