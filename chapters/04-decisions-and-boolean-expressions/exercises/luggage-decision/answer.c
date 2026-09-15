#include <stdio.h>

int main(void)
{
    int bag_weight = 18;

    if (bag_weight < 0)
    {
        puts("Invalid weight.");
    }
    else if (bag_weight <= 20)
    {
        puts("Bag accepted.");
    }
    else
    {
        puts("Bag is too heavy.");
    }

    return 0;
}

