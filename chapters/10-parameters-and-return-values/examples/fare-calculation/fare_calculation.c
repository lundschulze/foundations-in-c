#include <stdio.h>

double calculate_fare(int age)
{
    if (age < 0)
    {
        return 0.0;
    }

    return age < 16 ? 7.50 : 15.00;
}

int main(void)
{
    int age = 12;
    double fare = calculate_fare(age);

    printf("Ticket price: %.2f\n", fare);
    return 0;
}

