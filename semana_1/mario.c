#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // obtain a positive height between 1 and 8
    int h;
    do
    {
        h = get_int("height: ");
    }
    while (h < 1 || h > 8);

    // make pyramid
    for (int i = 0; i < h; i++)
    {
        // write spaces
        int spaces = h - i - 1;
        while (spaces > 0)
        {
            printf(" ");
            spaces--;
        }

        // write hashes
        int hashes = i + 1;
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }

        // space
        printf("  ");

        // make another pyramid
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }

        // Move the cursor down to create a new line
        printf("\n");
    }
}
