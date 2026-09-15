#include <stdio.h>

int main(void)
{
    int start = 3;

    if (start > 0)
    {
        while (start > 0)
        {
            printf("%d\n", start);
            start--;
        }
    }
    else if (start < 0)
    {
        while (start < 0)
        {
            printf("%d\n", start);
            start++;
        }
    }
    else
    {
        puts("Already at zero.");
    }

    return 0;
}

