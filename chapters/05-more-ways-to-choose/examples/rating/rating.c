#include <stdio.h>

int main(void)
{
    char rating = 'B';

    switch (rating)
    {
        case 'A':
            puts("Excellent result.");
            break;
        case 'B':
            puts("Strong result.");
            break;
        case 'C':
            puts("Satisfactory result.");
            break;
        default:
            puts("Rating not recognised.");
            break;
    }

    return 0;
}

