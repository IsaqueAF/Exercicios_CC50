#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // get the cash
    float cash;
    do
    {
        cash = get_float("Change Owed: ");
    }
    while (cash < 0);

    // count coins
    int cents = round(cash * 100);
    int coins = 0;

    while (cents > 0)
    {
        if (cents >= 25)
        {
            coins++;
            cents -= 25;
        }
        else if (cents >= 10)
        {
            coins++;
            cents -= 10;
        }
        else if (cents >= 5)
        {
            coins++;
            cents -= 5;
        }
        else if (cents >= 1)
        {
            coins++;
            cents -= 1;
        }
    }
    printf("%i\n", coins);
}
