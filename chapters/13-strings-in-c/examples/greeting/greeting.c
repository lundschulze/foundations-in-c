#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[40];

    printf("Your name: ");
    fflush(stdout);

    if (fgets(name, sizeof name, stdin) == NULL)
    {
        puts("No name was read.");
        return 1;
    }

    size_t newline = strcspn(name, "\n");
    name[newline] = '\0';

    printf("Welcome, %s.\n", name);
    return 0;
}

