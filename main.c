#include <stdio.h>
#include <stdlib.h>
//Lab8 Q1 function to get GCD of two numbers
int getGCD(int val1, int val2)
{
    int result = 0;
    for(int i =1; i<=val2; i++)
    {
        if((val1%i)==0 && (val2%i)==0)
        {
            result = i;
        }
    }
    return result;
}

int main()
{
    printf("%d", getGCD(8,12));
}
