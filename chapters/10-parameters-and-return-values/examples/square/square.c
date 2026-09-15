#include <stdio.h>

int square(int value)
{
    return value * value;
}

int main(void)
{
    int result = square(6);

    printf("Square of 6: %d\n", result);
    return 0;
}

