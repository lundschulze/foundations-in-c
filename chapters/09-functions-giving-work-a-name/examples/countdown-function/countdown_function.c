#include <stdio.h>

void show_countdown(void)
{
    for (int count = 3; count > 0; count--)
    {
        printf("%d\n", count);
    }

    puts("Lift off.");
}

int main(void)
{
    puts("Preparing departure.");
    show_countdown();
    puts("Departure sequence complete.");
    return 0;
}
