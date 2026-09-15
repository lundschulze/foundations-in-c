#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter an integer from 1 through 12: ");
    fflush(stdout);

    if (scanf("%d", &number) != 1)
    {
        puts("Please enter a whole number.");
        return 1;
    }

    if (number < 1 || number > 12)
    {
        puts("Number is outside the supported range.");
        return 1;
    }

    for (int multiplier = 1; multiplier <= 12; multiplier++)
    {
        printf("%d x %d = %d\n", number, multiplier, number * multiplier);
    }

    return 0;
}

