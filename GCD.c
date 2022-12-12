#include <stdio.h>
#include <stdlib.h>

int getLCM(int val1, int val2)
{
    int mult12 = val1 * val2;

    int resultGCD = 0, result = 0;
    for(int i =1; i<=val2; i++)
    {
        if((val1%i)==0 && (val2%i)==0)
        {
            resultGCD = i;
        }
    }

    result = mult12 / resultGCD;
    return result;
}

int main()
{
    printf("%d", getLCM(8,12));
}
