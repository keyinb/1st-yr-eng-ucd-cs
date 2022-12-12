/*  Cian Belton 19321726
    Computer Engineering 1
    Lab 1 Flight 8/10/2020
    This program will read in lower and upper distances and in step size defined
    by the user, it will calculate the time taken to the nearest minute to travel the printed
    distance.
*/

/*==================================================================
 * Systems header files
 *==================================================================*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
        /*Part A -asking for and reading in values and making sure values are positive*/
        /*Declaring variables to be read in as integers*/
        int low_dist, upper_dist, step_size;

        printf("Enter the lower limit on distance in km: ");
        scanf("%d",&low_dist);//Reading in the distance

        printf("Enter the upper limit on distance in km: ");
        scanf("%d",&upper_dist);

        printf("Enter the step size in km:               ");
        scanf("%d",&step_size);

        /*Truth statement used to check for errors such as a negative value or if the upper limit is less than the lower limit*/
        if (low_dist <0 || upper_dist <=0 || step_size <=0 || upper_dist < low_dist)
        {
            printf("Error: distance values must be positive");
            return 0;
        }
        /*Part B -printing top of the table format*/
        printf("===============================================\n");
        printf("| distance (km) |    hours    |    minutes    |\n");
        printf("|=============================================|\n");


        /*Part C1- Actual Calculation*/
        /*Declaring variables to be used in calculation */
        float avgv = 529/0.621371, time, distance = low_dist;
        while (distance <= upper_dist)/*While distance less than upper limit */
        {   /*Resetting hours and minutes to 0 each time it loops */
            int hours =0, minutes=0;
            time= (distance/avgv)*60.0;/* Time is now distance divided by average velocity and it is now in minutes*/
            while (time >= 60)
            {
                time = time-60; /* Decreasing time by 60 to find the minutes on their own*/
                hours++; /* Every time I take 60 mins off time hours goes up by 1*/
            }
            while (time >= 1)
            {
                time =time-1; /* Decreasing time by 1 to find the remainder*/
                minutes++; /*Adding the 1 to minutes*/
            }
            if (time >= 0.5)
            {
                minutes++; /*Rounding to the nearest minute*/
            }

            /*Part C2- Printing the rest of the table */
            if (distance<999 && minutes<=9)/*Use this format if distance is 3 digits and minutes is 1 digit */
            {
                printf("|    %.2f     |      %d      |       %d       |\n", distance, hours, minutes);
            }
            else if (distance<999 && minutes>=9)/*Use this format if distance is 3 digits and minutes is 2 digits  */
            {
                printf("|    %.2f     |      %d      |      %d       |\n", distance, hours, minutes);
            }
            else if (distance>999 && minutes<=9)/*Use this format if distance is 4 digits and minutes is 1 digit  */
            {
                printf("|   %.2f     |      %d      |       %d       |\n", distance, hours, minutes);
            }
            else/*Use this format if distance is 4 digits and minutes is 2 digits  */
            {
                printf("|   %.2f     |      %d      |      %d       |\n", distance, hours, minutes);
            }
            /*Incrementing Distance by the given step size */
            distance +=step_size;
        }
        /*Printing the last line*/
        printf("===============================================\n");

    return 0;

}
