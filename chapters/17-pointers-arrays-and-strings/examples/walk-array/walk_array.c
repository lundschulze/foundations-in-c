#include <stdio.h>

int main(void)
{
    int readings[] = {8, 13, 21};
    size_t count = sizeof readings / sizeof readings[0];
    int *current = readings;
    int *end = readings + count;

    while (current != end)
    {
        printf("%d\n", *current);
        current++;
    }
    return 0;
}
