/** lab4_main.c: Implements a front end for lab4_lib.c.
 *
 *
 * Name:Chufan Deng
 * Email:dengc@purdue.edu
 * Course: CNIT 315
 * Lab batch:010
 * Lab assignment: 4
 * Date:3/6/15
 *
 * Collaborators:
 gcc -W -Werror lab4_main.c lab4_lib.c -o lab4_main.o
 ./lab4_main.o

 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4_lib.h"

/* Function Prototypes */
int writeMenu(int *choice);
int clean_stdin();
int loopMenu();

/* Function: main()
 *
 * Parameters:
 *    - None
 *
 * Returns:
 *    - Integer:  0
 *
 * Expectations:
 *    - None
 */
int main(){
    /* Loop the menu */
    while(loopMenu()==1);
    
    return 0;
}

/* Function: writeMenu()
 *
 * Purpose of this function is to draw the user menu and receive their input.
 *
 *
 * Parameters:
 *    - *choice A pointer to the menuChoice variable.
 *
 * Returns:
 *    - Integer:  0 signifies the program exited with invalid input.
 *
 * Expectations:
 *    - None
 */
int writeMenu(int *choice)
{
    printf("\n\nThis program handles strings in unique ways, please choose a tool:\n");
    printf("\t1. String Input\t2. String Length\n");
    printf("\t3. Vowel Count\t4. Word Count\n");
    printf("\t5. Alpha-Numeric Test\t6. Substring Removal\n");
    printf("\t7. Concatenation\t8. Exit Program\n");
    printf("Please make a choice [1-8]: ");
    scanf("%d", choice);
    
    /* Validation */
    switch(*choice)
    {
        case 1:
            return 1;  // Return 1, the menu option selected
            break;
        case 2:
            return 2;  // Return 2, the menu option selected
            break;
        case 3:
            return 3;  // Return 3, the menu option selected
            break;
        case 4:
            return 4;  // Return 4, the menu option selected
            break;
        case 5:
            return 5;  // Return 4, the menu option selected
            break;
        case 6:
            return 6;  // Return 4, the menu option selected
            break;
        case 7:
            return 7;  // Return 4, the menu option selected
            break;
        case 8:
            return 8;  // Return 4, the menu option selected
            break;
        default:
            printf("\n\nThat choice was invalid.  Please choose a valid menu item, values 1 throuh 8 are acceptable.\n\n");
            // Clear scan flag
            clean_stdin();
            return 0;  // Return 0 as an error code for no proper selection.
            break;
    }
}

int loopMenu()
{
    char S1[256];
    char S2[256];
    char arr[500];
    char charac[1];
    int tmp = 0;
    /* A value to hold the menu item chosen */
    int menuChoice = 0;
    /* Show the main menu for user selection */
    while(writeMenu(&menuChoice)==0);
    
    /* User has made a decision at this point, run switch case */
    printf("\n");
    switch(menuChoice)
    {
            // Input a string
        case 1:
            
            printf("Please enter a string: ");
            clean_stdin();
            scanf("%[^\n]s",S1);
            acceptString(S1);
            break;
            // Check length of string
        case 2:
            printf("Please enter a string: ");
            clean_stdin();
            scanf("%[^\n]s",S1);
            printf("\n\nThe length of that string is %d characters.\n",findLength(S1));
            break;
            // Count vowels
        case 3:
            printf("Please enter a string: ");
            clean_stdin();
            scanf("%[^\n]s",S1);
            printf("\n\nThe number of vowels in that string is %d.\n",vowelCount(S1));
            break;
            // Count Words
        case 4:
            printf("Please enter a string: ");
            clean_stdin();
            scanf("%[^\n]s",arr);
            printf("\n\nThe number of words in that string is %d.\n",wordCount(arr));
            break;
            // Test AlphaNumeric
        case 5:
            printf("Please enter a single character: ");
            clean_stdin();
            scanf("%c",charac);
            tmp = alphanum(charac[0]);
            if(tmp==1)
            {
                printf("\n\nThis character is alphabetical or numeric. (1)\n");
            }
            else
            {
                printf("\n\nThis character is not alphabetical or numeric. (0)\n");
            }
            break;
            // Count vowels
        case 6:
            clean_stdin();
            printf("\n\n\nEnter text for string 1: ");
            gets(S1);
            
            printf("\nEnter the text to remove from string 1: ");
            gets(S2);
            
            while (removestr(S1, S2));
            printf("\n\nThe new string is:\n");
            puts(S1);
            printf("\nPress enter to continue.\n");
            break;
            // Concatenate
        case 7:
            clean_stdin();
            printf("\n\n\nEnter text for string 1: ");
            gets(S1);
            
            printf("\nEnter the text to concatenate to string 1: ");
            gets(S2);
            
            concat(S1, S2);
            printf("Press enter to continue.\n");
            break;
            // Exit the program
        case 8:
            printf("\nClosing program!\n");
            exit(0);
            break;
            
    }
    clean_stdin();
    return 1;
}

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}