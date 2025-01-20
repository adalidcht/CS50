#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's you're name: ");
    printf("Hello, %s\n", name);
}