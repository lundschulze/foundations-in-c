#include <stdio.h>

int main(void)
{
    int choice = 2;

    do
    {
        printf("Choice: %d\n", choice);
        choice--;
    }
    while (choice > 0);

    return 0;
}

