#include <stdio.h>

int main(void)
{
    int age;

    printf("Enter your age: ");
    fflush(stdout);

    int items_read = scanf("%d", &age);
    if (items_read != 1)
    {
        puts("That was not a whole number.");
        return 1;
    }

    printf("Next year you will be %d.\n", age + 1);
    return 0;
}

