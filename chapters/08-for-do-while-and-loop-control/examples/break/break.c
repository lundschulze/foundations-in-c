#include <stdio.h>

int main(void)
{
    for (int value = 1; value <= 10; value++)
    {
        if (value == 4)
        {
            break;
        }

        printf("%d\n", value);
    }

    return 0;
}

