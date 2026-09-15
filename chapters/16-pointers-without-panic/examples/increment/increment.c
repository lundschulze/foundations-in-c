#include <stdio.h>

static void increment(int *value)
{
    (*value)++;
}

int main(void)
{
    int visits = 41;

    increment(&visits);
    increment(&visits);
    printf("Visits: %d\n", visits);
    return 0;
}
