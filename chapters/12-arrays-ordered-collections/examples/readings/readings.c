#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int readings[] = {12, 15, 14, 18, 16};
    size_t count = sizeof readings / sizeof readings[0];

    for (size_t index = 0; index < count; index++)
    {
        printf("Reading %zu: %d\n", index, readings[index]);
    }

    return 0;
}

