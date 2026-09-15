#include <stdio.h>

static int copy_values(int *destination, size_t destination_capacity,
                       const int *source, size_t source_count)
{
    if (source_count > destination_capacity)
    {
        return 0;
    }
    for (size_t index = 0; index < source_count; index++)
    {
        destination[index] = source[index];
    }
    return 1;
}

int main(void)
{
    int source[] = {8, 13, 21};
    int destination[3] = {0};
    size_t count = sizeof source / sizeof source[0];

    if (!copy_values(destination, 3, source, count))
    {
        fputs("Destination is too small.\n", stderr);
        return 1;
    }
    for (size_t index = 0; index < count; index++)
    {
        printf("%d\n", destination[index]);
    }
    return 0;
}
