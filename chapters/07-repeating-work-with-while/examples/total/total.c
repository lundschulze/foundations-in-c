#include <stdio.h>

int main(void)
{
    int value = 1;
    int total = 0;

    while (value != 0)
    {
        printf("Enter a value, or 0 to finish: ");
        fflush(stdout);

        if (scanf("%d", &value) != 1)
        {
            puts("Input was not a whole number.");
            return 1;
        }

        total = total + value;
    }

    printf("Total: %d\n", total);
    return 0;
}

