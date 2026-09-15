#include <stdio.h>

int main(void)
{
    int age = 12;
    double fare = age < 16 ? 7.50 : 15.00;

    printf("Ticket price: %.2f\n", fare);
    return 0;
}

