/*
    Lab 4 - hangman
    Cian Belton 19321726
    29/11/2020
    This program will run the game of hangman by reading into a text file and
    taking in guesses from the user

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>/* needed for the string functions*/

#define MAXSTRING 1000 /*all strings will be of this size */

/* Functions*/

char *string_hide(char original[], char star_string[]); /*Function to make the text read in from the file turn to stars */
int check_string(char original[], char star_string[], char letter);/*Check the string for the letter input by user */
int check_letter(char *letter_guess, char letter);/* check the string to see if the letter has been put in already */
char letter_guess[MAXSTRING]; /*Char string to hold the guessed letters */
char *ltrptr = &letter_guess[0];/* pointer to 1st position in gueesed letter string */

int main()
{
    char original[MAXSTRING], l_or_w, repeat = 'y';/*Declaring char strings and values */
    char star_string[MAXSTRING], char_file[MAXSTRING];

    do /*do this loop while repeat is y */
    {
        /*int variables for looping and turns is the given amount in hangman */
        int turns = 10, count = 0, j =0;
        /*Procedure to read in the desired file */
        printf("Give a filename with the unknown word: ");
        scanf("%s", char_file);

        FILE *fptr1 = fopen(char_file, "r");/*Creating a file pointer and reading into this file using fopen function */

        if( fptr1 == NULL )/*if we cant find the file or some other error */
        {
            printf(" Error, can't open file\n");
            exit(EXIT_FAILURE);/*will have to run the program again */
        }

        fgets(original, MAXSTRING, fptr1); /*get the file pointer and write whatever was in the imported file into string called origianl*/

        fclose(fptr1);/*close the pointer to prevent an error */

        star_string[MAXSTRING] = *string_hide(original, star_string); /*calling the function to make the star-string */
        /*printing required message */
        printf("Ready to Start!\n");
        printf("The word is:   %s\n\n", star_string);
        printf("Number of turns remaining:  %d\n", turns);
        /*count is the break variable */
        while(count == 0)
        {   /*statement as specified */
            printf("Would you like to guess the word [w] or guess a letter [l]:  ");
            scanf(" %c", &l_or_w);
            /*procedure for a letter guess or a word guess */
            char letter;
            if(l_or_w == 'l')
            {
                printf("What letter have you chosen?:  ");
                scanf(" %c", &letter);
                /*calling the check function to see if that letter has been guessed already */
                if( check_letter(letter_guess, letter) == 1)
                {
                    printf("\nYou have already guessed that letter.\n");
                    printf("Pick another letter:  ");
                    scanf(" %c", &letter);
                }
                letter_guess[j] = letter;/*filling the guessed letter array with the guessed letters */
                j++;
                /*fucntion to check if the guess was 'right' */
                int right = check_string(original, star_string, letter);
                /*0 means incorrect guess */
                if(right == 0)
                {
                    turns = turns - 1;
                    printf("\n***********************************************\n");
                    printf("Bad choice\n");
                    printf("The word is: %s\n", star_string);
                    printf("Number of turns remaining: %d\n", turns);
                }/*1 means correct guess */
                if(right == 1)
                {
                    printf("\n***********************************************\n");
                    printf("Good choice!\n");
                    printf("The word is:  %s\n", star_string);
                    printf("Number of turns remaining: %d\n", turns);
                }/*2 means we have guessed the final letter in the word and can now break from while loop */
                 if(right == 2)
                {
                    count = 1;/*break from while loop */
                    printf("\n\nCongratulations!\n\n\n");
                    printf("***********************************************\n");
                }
            }
            /*procedure if we guess a word */
            if(l_or_w == 'w')
            {      /*populate the guessed word into this string */
                char user_guess[MAXSTRING];
                printf("What is your guessed word?: ");
                scanf("%s", user_guess);
                /*if this guess matches the original */
                if((strcmp(original, user_guess)) == 0)
                {
                    count = 1; /*break from while loop  */
                    printf("\n\nCongratulations!\n\n\n");
                    printf("***********************************************\n");
                }/*  else the guess was incorrect so detuct a turn and continue*/
                else
                {
                    turns = turns - 1;
                    printf("\n\nBad choice\n\n\n");
                    printf("The word is:  %s\n", star_string);
                    printf("Number of turns remaining: %d\n", turns);
                    printf("***********************************************\n");
                }
            }
            /*if we run out of turns */
            if(turns == 0)
            {
                printf("You have run out of turns. Better luck next time. The word was %s.\n", original);
                count = 1;/*break from while loop */
            }
        }
        /*procedure to play the game again */
        printf("\nDo you want to play again ([y] or [n])? ");
        scanf(" %c", &repeat);/*space in front of all %c scans to ensure letter is read in correctly */
        /*if we repeat, then reset to the top */
        if(repeat == 'y')
        {
            printf("\n\n");
            continue;
        }/*else break and return 0 */
        else
        {
            break;
        }
    }while(repeat == 'y');/*end of do while loop */

    return 0;
}

char *string_hide(char original[], char star_string[])
{
    int i = 0;
    /*in our new string, fill it with *'s so that it is same length as original */
    for(i = 0; i < strlen(original); i++)
    {
        star_string[i] = '*';
    }
    /*return the starred string */
    return star_string;
}

int check_string(char original[], char star_string[], char letter)
{
    int count = 0, right = 0;

    for(count = 0; count < strlen(original); count++)
    {   /*if a letter is guessed correctly, we show this correct guess in the star string */
        if(original[count] == letter)
        {
            star_string[count] = original[count];
            right = 1;/*right is 1, a correct guess */
        }
    }

    if((strcmp(original, star_string)) == 0)
    {   /* if all the letters in star string are filled in on the last letter guess we are now done, so can break out of while loop above */
        right = 2;
    }
    /*if the guess was incorrect right stays as 0 and we lose a turn above */
    return right;
}

int check_letter(char *letter_guess, char letter)
{
    int check = 0, i;
    /*increment until we get to end of letter_guess */
    for(i = 0; letter_guess[i] != '\0' ; i++)
    {   /*if any of the letters in letter_guess is the letter guessed this time round, it has been repeated */
        if( *(ltrptr + i) == letter)
        {   /*so check is true */
            check = 1;
        }/*else it is a new guess, so continue as normal */
        else
        {
            check = 0;
        }
    }

    return  check;
}

