#include <stdio.h>

int main(void)
{
    int quantity;

    printf("Enter a quantity from 0 through 100: ");
    fflush(stdout);

    if (scanf("%d", &quantity) != 1)
    {
        puts("Please enter a whole number.");
        return 1;
    }

    if (quantity < 0 || quantity > 100)
    {
        puts("Quantity is outside the supported range.");
        return 1;
    }

    printf("Accepted quantity: %d\n", quantity);
    return 0;
}

