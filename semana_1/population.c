#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // get start size of population
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // get end size of population
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // calculate years
    int years = 0;
    while (true)
    {
        if (start >= end) {
            break;
        }
        start += round(start / 3) - round(start / 4);
        years++;
    }
    printf("Years: %i\n", years);
}
