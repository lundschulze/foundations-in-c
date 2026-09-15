#include <stdio.h>

int main(void)
{
    int answer = 42;
    int *answer_pointer = &answer;

    printf("Directly: %d\n", answer);
    printf("Through the pointer: %d\n", *answer_pointer);
    *answer_pointer = 43;
    printf("After the change: %d\n", answer);
    return 0;
}
