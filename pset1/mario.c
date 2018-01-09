#include <stdio.h>
#include <cs50.h>

// Prints out a double half-pyramid using hashes (#) for blocks, of a user-specified height.
int getHeightFromUser();
void printPyramid(int height);

int main(void)
{
    int height = getHeightFromUser();
    printPyramid(height);
}

int getHeightFromUser()
{
    // Height must be a non-negative integer no greater than 23
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    return n;
}

void printPyramid(int height)
{
    char blockType = '#';

    for (int j = 0; j < height; j++)
    {
        // Print the first pyramid
        for (int i = 0; i < height; i++)
        {
            if (height - i - 1 <= j)
            {
                printf("%c", blockType);
            }
            else
            {
                printf(" ");
            }
        }

        // Print the gap
        printf("  ");

        // Print the second pyramid
        for (int i = 0; i < height; i++)
        {
            if (i <= j)
            {
                printf("%c", blockType);
            }
        }

        // Finally end the line
        printf("\n");
    }
}
