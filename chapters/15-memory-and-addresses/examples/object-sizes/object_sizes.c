#include <stdio.h>

int main(void)
{
    int answer = 0x2A;

    printf("char: %zu byte(s)\n", sizeof(char));
    printf("int: %zu byte(s)\n", sizeof(int));
    printf("double: %zu byte(s)\n", sizeof(double));
    printf("answer: %zu byte(s), value %d\n", sizeof answer, answer);
    return 0;
}
