#include <cs50.h>
#include <math.h>
#include <stdio.h>

void VerifyCard(long number);

int main(void)
{
    // get number
    long number;
    do
    {
        number = get_long("Change Owed: ");
    }
    while (number < 0);

    // verify card
    VerifyCard(number);
}

// custom functions
int SumDigits(int number)
{
    return number % 10 + number / 10 % 10;
}

// exponential calculate
long Pow(int base, int exponent)
{
    long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int GetSizeOfNumber(long number)
{
    int size = 0;
    for (int i = 0; i < 16; i++)
    {
        if (Pow(10, i) > number)
        {
            break;
        }
        size = i + 1;
    }
    return size;
}

int digit(long number, int position)
{
    return number / Pow(10, position - 1) % 10;
}

void VerifyCard(long number)
{

    const int size = GetSizeOfNumber(number);
    int result = 0;

    // Verifiy if card is valid
    for (int i = 2; i < 17; i += 2)
    {
        result += SumDigits(digit(number, i) * 2);
    }

    for (int i = 1; i < 17; i += 2)
    {
        result += digit(number, i);
    }

    // check what type it is
    if (result % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (digit(number, size) == 4)
        {
            if (size == 13 || size == 16)
            {
                printf("VISA\n");
                return;
            }
        }
        if (digit(number, size) == 3)
        {
            if (digit(number, size - 1) == 4 || digit(number, size - 1) == 7)
            {
                if (size == 15)
                {
                    printf("AMEX\n");
                    return;
                }
            }
        }
        if (digit(number, size) == 5)
        {
            for (int i = 1; i < 6; i++)
            {
                if (digit(number, size - 1) == i && size == 16)
                {
                    printf("MASTERCARD\n");
                    return;
                }
            }
        }
        printf("INVALID\n");
    }
}
