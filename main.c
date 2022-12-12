#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lab10q6 Cian Belton
void reverse_string(char *string)//going to revers a string, including changing the capital letters
{
    char *begin, *end, temp; // Begin and end are pointers and temp will be an intermediatre
    begin = string;//Begin pointing to string
    end = string;
    int i, length = strlen(string);//length is the lenth of the string
    for(i =0; i< length-1; i++) //Bringing end up to the final value in the string, while begin is still at the start
    {
        end++;
    }
    for(i =0; i < length/2; i++)// Will repeat 1/2*length as 2 values swapped simultaenously each time
    {
        if (i ==0)//Switching the first letter and last letter, including change in case
        {
             string[i] = string[i] + 'a' - 'A'; //Swithing first letter to lowercase
             temp =*end;//temp is now last letter
            *end = *begin;//end is now first letter
            *begin = temp;//start is now last letter
             string[i] = string[i] + 'A' - 'a';//raise the currrent first letter to capial
        }
        else//will run for every other value
        {
            temp =*end;
            *end = *begin;
            *begin = temp;
        }

        begin++;
        end--;
    }
}


int main()
{
    char str[] = "Lived";
    reverse_string(str);
    printf("%s\n", str);
}
