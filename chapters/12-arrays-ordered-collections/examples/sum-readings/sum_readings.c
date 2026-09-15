#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int readings[] = {12, 15, 14, 18, 16};
    size_t count = sizeof readings / sizeof readings[0];
    int total = 0;

    for (size_t index = 0; index < count; index++)
    {
        total += readings[index];
    }

    printf("Total: %d\n", total);
    return 0;
}

