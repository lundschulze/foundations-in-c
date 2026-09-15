#include <stddef.h>
#include <stdio.h>

void print_readings(const int values[], size_t count)
{
    for (size_t index = 0; index < count; index++)
    {
        printf("%d\n", values[index]);
    }
}

int main(void)
{
    int readings[] = {12, 15, 14, 18, 16};
    size_t count = sizeof readings / sizeof readings[0];

    print_readings(readings, count);
    return 0;
}

