#include <stddef.h>
#include <stdio.h>

int main(void)
{
    int measurements[] = {12, 15, 14, 18, 16, 11, 17};
    size_t count = sizeof measurements / sizeof measurements[0];
    int total = 0;
    int smallest = measurements[0];
    int largest = measurements[0];

    for (size_t index = 0; index < count; index++)
    {
        int value = measurements[index];

        printf("Measurement %zu: %d\n", index, value);
        total += value;

        if (value < smallest)
        {
            smallest = value;
        }

        if (value > largest)
        {
            largest = value;
        }
    }

    printf("Total: %d\n", total);
    printf("Smallest: %d\n", smallest);
    printf("Largest: %d\n", largest);
    return 0;
}

