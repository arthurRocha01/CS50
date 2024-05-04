#include <cs50.h>
#include <stdio.h>

void brickBuilder();

int main(void)
{
    int input;
    do
    {
        input = get_int("height: ");
    }
    while (input < 1 || input > 8);
        brickBuilder(input);
}

void brickBuilder(height)
{
    int brickHeight = height;
    int steps = height - 1;
    for (int h = 0; h < height; h++) // height
    {
        for (int s = 0; s < steps; s++) // degraus
        {
            printf(" ");
        }
        steps--;
        for (int b = brickHeight; b <= height; b++) // tijolos/hashes
        {
            printf("#");
        }
        printf("  ");
        for (int b = brickHeight; b <= height; b++)
        {
            printf("#");
        }
        brickHeight--;
        printf("\n");
    }
}
