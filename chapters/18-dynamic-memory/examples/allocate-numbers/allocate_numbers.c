#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count = 5;
    int *numbers = malloc(count * sizeof *numbers);

    if (numbers == NULL)
    {
        fputs("Could not allocate memory.\n", stderr);
        return 1;
    }
    for (size_t index = 0; index < count; index++)
    {
        numbers[index] = (int)(index + 1);
        printf("%d\n", numbers[index]);
    }
    free(numbers);
    numbers = NULL;
    return 0;
}
