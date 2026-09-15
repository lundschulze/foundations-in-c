#include <stdio.h>

int main(void)
{
    int temperature;

    printf("Temperature in Celsius: ");
    fflush(stdout);

    if (scanf("%d", &temperature) != 1)
    {
        puts("Please enter a whole number.");
        return 1;
    }

    if (temperature < -100 || temperature > 100)
    {
        puts("Temperature is outside the supported range.");
        return 1;
    }

    printf("Recorded temperature: %d C\n", temperature);
    return 0;
}

