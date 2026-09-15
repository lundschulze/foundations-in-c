#include <stdio.h>

static void clamp(int *value, int minimum, int maximum)
{
    if (*value < minimum)
    {
        *value = minimum;
    }
    else if (*value > maximum)
    {
        *value = maximum;
    }
}

int main(void)
{
    int values[] = {-4, 5, 16};
    size_t count = sizeof values / sizeof values[0];

    for (size_t index = 0; index < count; index++)
    {
        clamp(&values[index], 0, 10);
        printf("%d\n", values[index]);
    }
    return 0;
}
