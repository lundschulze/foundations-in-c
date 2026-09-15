#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool has_ticket = true;
    bool has_towel = true;

    if (has_ticket && has_towel)
    {
        puts("Boarding approved.");
    }
    else
    {
        puts("Check the travel requirements.");
    }

    return 0;
}

