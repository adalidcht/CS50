#include <cs50.h>
#include <stdio.h>

void pyramid(int height);
void bricks(int brick);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height for the pyramid? (1-8): ");
    }
    while (height < 1 || height > 8);

    pyramid(height);
}

void pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        bricks(i);
        printf("  ");
        bricks(i);
        printf("\n");
    }
}

void bricks(int brick)
{
    for (int k = 0; k < brick; k++)
    {
        printf("#");
    }
}
