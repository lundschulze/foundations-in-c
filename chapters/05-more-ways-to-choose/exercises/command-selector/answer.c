#include <stdio.h>

int main(void)
{
    int command = 1;

    switch (command)
    {
        case 1:
            puts("Open selected.");
            break;
        case 2:
            puts("Save selected.");
            break;
        case 3:
            puts("Print selected.");
            break;
        case 4:
            puts("Exit selected.");
            break;
        default:
            puts("Unknown command.");
            break;
    }

    return 0;
}

