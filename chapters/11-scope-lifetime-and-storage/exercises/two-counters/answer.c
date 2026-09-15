#include <stdio.h>

void show_automatic_counter(void)
{
    int counter = 0;

    counter++;
    printf("Automatic: %d\n", counter);
}

void show_static_counter(void)
{
    static int counter = 0;

    counter++;
    printf("Static: %d\n", counter);
}

int main(void)
{
    for (int call = 0; call < 3; call++)
    {
        show_automatic_counter();
        show_static_counter();
    }

    return 0;
}

