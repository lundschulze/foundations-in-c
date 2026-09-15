#include <stdio.h>

int main(void)
{
    int answer = 42;

    printf("Value: %d\n", answer);
    printf("Address: %p\n", (void *)&answer);
    return 0;
}
