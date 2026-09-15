#include <stdio.h>

int main(void)
{
    int outer = 42;

    printf("Outer: %d\n", outer);

    {
        int inner = 7;
        printf("Inner: %d\n", inner);
    }

    printf("Outer again: %d\n", outer);
    return 0;
}

