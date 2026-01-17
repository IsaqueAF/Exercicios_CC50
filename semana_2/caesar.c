#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Handle the command line argument and obtain the difference.
    int difference = 0;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] >= '0' && argv[1][i] <= '9')
        {
            difference += (argv[1][i] - '0') * (int) pow(10, n - i - 1);
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // get plaintext
    string plaintext = get_string("plaintext: ");

    // encrypt
    string ciphertext = plaintext;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (tolower(plaintext[i]) >= 'a' && tolower(plaintext[i]) <= 'z')
        {
            if (islower(plaintext[i]))
            {
                ciphertext[i] = 'a' + ((plaintext[i] - 'a' + difference) % 26);
            }
            else
            {
                ciphertext[i] = 'A' + ((plaintext[i] - 'A' + difference) % 26);
            }
        }
    }

    // show result
    printf("ciphertext: %s\n", ciphertext);
}
