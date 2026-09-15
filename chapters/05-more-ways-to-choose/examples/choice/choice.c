#include <stdio.h>

int main(void)
{
    int choice = 2;

    switch (choice)
    {
        case 1:
            puts("Status selected.");
            break;
        case 2:
            puts("Navigation selected.");
            break;
        case 3:
            puts("Settings selected.");
            break;
        default:
            puts("Unknown selection.");
            break;
    }

    return 0;
}

