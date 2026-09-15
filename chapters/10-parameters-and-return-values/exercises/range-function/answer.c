#include <stdio.h>

int is_in_range(int value, int minimum, int maximum);

int main(void)
{
    int minimum = 10;
    int maximum = 20;

    printf("10: %d\n", is_in_range(10, minimum, maximum));
    printf("15: %d\n", is_in_range(15, minimum, maximum));
    printf("20: %d\n", is_in_range(20, minimum, maximum));
    printf("9: %d\n", is_in_range(9, minimum, maximum));
    printf("21: %d\n", is_in_range(21, minimum, maximum));

    return 0;
}

int is_in_range(int value, int minimum, int maximum)
{
    return value >= minimum && value <= maximum;
}
