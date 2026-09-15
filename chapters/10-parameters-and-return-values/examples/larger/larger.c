#include <stdio.h>

int larger(int first, int second);

int main(void)
{
    int result = larger(17, 42);

    printf("Larger value: %d\n", result);
    return 0;
}

int larger(int first, int second)
{
    if (first > second)
    {
        return first;
    }

    return second;
}

