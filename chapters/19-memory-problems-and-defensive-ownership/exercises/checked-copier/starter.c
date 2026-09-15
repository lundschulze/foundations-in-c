#include <stddef.h>

static int copy_doubles(double *destination, size_t destination_capacity,
                        const double *source, size_t source_count)
{
    /* TODO: copy only when the complete source fits. */
    (void)destination;
    (void)destination_capacity;
    (void)source;
    (void)source_count;
    return 0;
}

int main(void)
{
    double source[] = {1.5, 2.5, 3.5};
    double destination[3] = {0.0};
    return copy_doubles(destination, 3, source, 3) ? 0 : 1;
}
