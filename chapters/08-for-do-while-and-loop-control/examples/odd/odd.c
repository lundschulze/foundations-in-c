#include <stdio.h>

int main(void)
{
    for (int value = 1; value <= 7; value++)
    {
        if (value % 2 == 0)
        {
            continue;
        }

        printf("%d\n", value);
    }

    return 0;
}

