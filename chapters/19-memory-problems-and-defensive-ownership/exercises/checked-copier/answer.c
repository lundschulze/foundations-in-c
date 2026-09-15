#include <assert.h>
#include <stddef.h>

static int copy_doubles(double *destination, size_t destination_capacity,
                        const double *source, size_t source_count)
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
    double source[] = {1.5, 2.5, 3.5};
    double exact[3] = {0.0};
    double excess[5] = {0.0};
    double small[2] = {9.0, 9.0};

    assert(copy_doubles(exact, 3, source, 3));
    assert(copy_doubles(excess, 5, source, 3));
    assert(!copy_doubles(small, 2, source, 3));
    assert(exact[2] == 3.5);
    assert(excess[0] == 1.5);
    assert(small[0] == 9.0 && small[1] == 9.0);
    return 0;
}
