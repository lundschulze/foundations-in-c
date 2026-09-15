#include <assert.h>

static int clamp(int value, int minimum, int maximum)
{
    if (value < minimum)
    {
        return minimum;
    }
    if (value > maximum)
    {
        return maximum;
    }
    return value;
}

int main(void)
{
    assert(clamp(5, 0, 10) == 5);
    assert(clamp(0, 0, 10) == 0);
    assert(clamp(10, 0, 10) == 10);
    assert(clamp(-1, 0, 10) == 0);
    assert(clamp(11, 0, 10) == 10);
    return 0;
}
