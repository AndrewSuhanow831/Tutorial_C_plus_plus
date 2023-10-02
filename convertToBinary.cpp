#include <math.h>

void convertToBinary(int number, int &bin, int &deg)
{
    if (number / 2 != 0)
    {
        bin += (number % 2) * pow(10, deg);
        ++deg;
        convertToBinary(number / 2, bin, deg);
    }
    else
        bin += pow(10,deg);
};

int convertToBinary(int number, int deg)
{
    if (number == 0)
        return 0;        
    else
    {
        return convertToBinary(number / 2, deg * 10) + (number % 2) * deg;
    }
};