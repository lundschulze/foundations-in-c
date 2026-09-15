#include <stdio.h>

int main(void)
{
    puts("Result: no record saved.");
    fputs("Diagnostic: the practice destination was unavailable.\n", stderr);
    return 1;
}
