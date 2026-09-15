#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count = 2;
    int *values = malloc(count * sizeof *values);

    if (values == NULL)
    {
        fputs("Initial allocation failed.\n", stderr);
        return 1;
    }
    values[0] = 13;
    values[1] = 21;

    size_t new_count = 5;
    if (new_count > SIZE_MAX / sizeof *values)
    {
        fputs("Requested array is too large.\n", stderr);
        free(values);
        return 1;
    }
    int *resized = realloc(values, new_count * sizeof *values);
    if (resized == NULL)
    {
        fputs("Resize failed.\n", stderr);
        free(values);
        return 1;
    }
    values = resized;
    for (size_t index = count; index < new_count; index++)
    {
        values[index] = (int)(index + 1) * 10;
    }
    count = new_count;
    for (size_t index = 0; index < count; index++)
    {
        printf("%d\n", values[index]);
    }
    free(values);
    return 0;
}
