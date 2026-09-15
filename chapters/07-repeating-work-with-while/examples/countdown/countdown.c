#include <stdio.h>

int main(void)
{
    int count = 3;

    while (count > 0)
    {
        printf("%d\n", count);
        count = count - 1;
    }

    puts("Lift off.");
    return 0;
}

