#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Handle the command line argument and obtain the key.
    char key[26];

    if (argc != 2)
    {
        printf("You only need to pass one command line argument.\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Pass through exactly a scrambled alphabet.\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (tolower(argv[1][i]) >= 'a' && tolower(argv[1][i]) <= 'z')
        {
            for (int j = 0, num = i; j < num; j++)
            {
                if (tolower(argv[1][i]) == key[j])
                {
                    printf("Don't repeat the character.\n");
                    return 1;
                }
            }
            key[i] = tolower(argv[1][i]);
        }
        else
        {
            printf("You should only pass characters from the alphabet.\n");
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
                ciphertext[i] = key[plaintext[i] - 'a'];
            }
            else
            {
                ciphertext[i] = toupper(key[plaintext[i] - 'A']);
            }
        }
    }

    // show result
    printf("ciphertext: %s\n", ciphertext);
}
