#include <stdio.h>

struct Traveller
{
    char name[40];
    int age;
    int bags;
};

static void print_traveller(struct Traveller traveller)
{
    printf("%s is %d and carries %d bags.\n",
           traveller.name, traveller.age, traveller.bags);
}

int main(void)
{
    struct Traveller traveller = {
        .name = "Maya",
        .age = 42,
        .bags = 2
    };
    struct Traveller copy = traveller;

    copy.bags = 3;
    print_traveller(traveller);
    print_traveller(copy);
    return 0;
}
