#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t count = 4;
    int *counters = calloc(count, sizeof *counters);

    if (counters == NULL)
    {
        fputs("Could not allocate counters.\n", stderr);
        return 1;
    }
    counters[1]++;
    counters[1]++;
    counters[3]++;
    for (size_t index = 0; index < count; index++)
    {
        printf("%d\n", counters[index]);
    }
    free(counters);
    return 0;
}
