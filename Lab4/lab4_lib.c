/** lab4_lib.c: implements sorting and searching functions.
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
 *
 */
#include <stdio.h>
#include <string.h> //for memcpy
#include <stdlib.h>
#include "lab4_lib.h"
#define MAX_STRING_LEN 80


size_t   strlen(const char *);
int length=0;
int count=0;

/*ACCEPT STRING SECTION*/
int acceptString(char string[])
{
    if(string[0]=='\0')
    {
        printf("Error: Input was NULL\n");
        return 1;
    }
    
    
    printf("Here is the string:\n");
    puts(string);
    return 0;
}

/*FIND LENGTH SECTION*/
int findLength(char string[])
{
    if(string[0]=='\0')
    {
        return 0;
    }
    length = strlen(string);
    
    //printf("Length of entered string = %d\n",length);
    
    return length;
}
/*COUNT VOWELS SECTION*/
int vowelCount(char str[])
{
    int i = 0;
    int v = 0;
    while(str[i] != '\0')
    {
        if(str[i]=='A'|| str[i] == 'a')
        {
            v++;
            i++;
        }
        else if(str[i] == 'E' || str[i] == 'e')
        {
            v++;
            i++;
        }
        else if(str[i] == 'I' || str[i] == 'i')
        {
            v++;
            i++;
        }
        else if(str[i] == 'O' || str[i] == 'o')
        {
            v++;
            i++;
        }
        else if(str[i] == 'U' || str[i] == 'u')
        {
            v++;
            i++;
        }
        else
        {
            i++;
        }
    }
    return v;
}

/*COUNT WORDS SECTION*/
int wordCount(char str[])
{
    int i = 0;
    int wc = 0;
    typedef enum { false, true } bool; // this is neat, didn't know about it
    bool flag = true; // true means counting letters
    bool counted = false; // we counted a sequence of separators
    bool startCounting = false; //don't start counting until a letter is found (fixes multiple starting spaces)
    // Immediate exit condition
    if(str[0]=='\0')
    {
        return wc;
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        flag = true;
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            flag=false; // we are counting separators
        }
        else
        {
            startCounting=true;
            counted=false;
            flag=true;
        }
        if(flag==false && counted==false)
        {
            if(startCounting==true)
            {
                wc++;
            }
            counted = true;
        }
        // Check the next character for \0
        if(str[(i+1)] == '\0')
        {
            // If the current character is a letter of some sort...
            if(flag==true) // flag = true means this is a letter
            {
                // Count the last word, which is otherwise skipped
                wc++;
            }
        }
    }
    
    // done with for loop
    // If the wordcount is still zero...
    if(wc==0)
    {
        // And the first character of the string is not some separator
        if(str[0] != ' ' && str[0] != '\t' && str[0] != '\n') // had to use && not || operators
        {
            // There is at least one word
            wc++;
        }
    }
    
    /* This part was always re-assigning wc = 0 if there was a separator at the beggining, which broke the answers
     if(str[0] == ' ' || str[0] == '\t' || str[0] == '\n')
     {
     wc = 0;
     }
     */
    return wc;
}

/*ALPHANUMERIC SECTION*/

/*SUBSTRING SECTION*/





void concat(char first[], char second[])
{
    /* Initialize */
    int i, j;
    i = 0;
    
    /* Concatenate algorithm */
    
    while (first[i] != '\0') {
        i++;
    }
    
    j = 0;
    
    while (second[j] != '\0') {
        first[i] = second[j];
        j++;
        i++;
    }
    
    first[i] = '\0';
    printf("\n%s\n",first);
}

int removestr(char *line, char *search){
    
    if(search[0]=='\0'){
        printf("Error: Input was NULL\n");
        return 0;
    }
    while (*line){
        char *s = search;
        char *l = line ;
        while (*s && *s==*l){
            ++s;
            ++l;}
        if (!*s){
            while( *l) *line++=*l++;
            *line=0;
            return 1;
        }
        ++line;
    }
    return 0;
}



//Substring Function
void substring(char string[], char sub[], int pos, int len)
{
    int c = 0;
    
    while (c < len)
    {
        sub[c] = string[pos+c-1];
        c++;
    }
    sub[c] = '\0';
}
//Alphanumeric Funciton
int alphanum( char c)
{
    if( c >= 'a' && c <= 'z')
    {
        return 1;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    if(c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}