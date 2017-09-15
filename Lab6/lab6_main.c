/**
 *
 * Name:Chufan Deng
 * Email:dengc@purdue.edu
 * Course: CNIT 315
 * Lab batch:010
 * Lab assignment: 6
 * Date:4/13/15
 *
 * Collaborators:
 gcc -W -Werror lab6_main.c -o lab6_main.o
 ./lab6_main.o

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



struct student
{
    char firstName[10];
    char lastName[10];
    char PUID[10];
    int age;
    struct student *next;
};

//create_list_no_nodes
struct student *head;
struct student *current;

struct student *in, *out, *sameOut;

//AddNode
struct student *AddNode(char *firstName, char *lastName, char *PUID, int age)
{
    struct student *new;
    
    new = (struct student *) malloc( sizeof(struct student) );
    
    strcpy(new->firstName, firstName);
    strcpy(new->lastName, lastName);
    strcpy(new->PUID,PUID);
    new->age = age;
    new->next=NULL;
    
    return(new);
}

//Stack

//push
void push(struct student *new)
{
    if(new==(struct student *) NULL)
    {
        printf("\n Failed to allocate memory for this stack.");
        exit(1);
    }
    
    new->next=head;
    head=new;

}

//pop
void pop()
{
    struct student *temp;
    
    temp=head->next;
    head=NULL;
    head=temp;
    
}

//size
int size(struct student *one)
{
    int i=0;
    
    while(one!=NULL)
    {
        i++;
        one=one->next;
    }
    return i;
}

//empty
bool empty(struct student *one)
{
    if(size(one)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
struct student *traverse()
{
    current=out;
    
    while( current->next != NULL )
    {
        current = current->next;
    }
    
    return current;
}
*/

//PrintStack
void PrintStack()
{
    struct student *contents,*current;
    
    contents=head;
    printf("Information: \n");
    
    while(contents!=NULL)
    {
        if(contents==sameOut)
        {
            printf("%s\t %s\t %s\t %d\n",contents->firstName,contents->lastName,contents->PUID,contents->age);
            break;
        }
        
        printf("%s\t %s\t %s\t %d\n",contents->firstName,contents->lastName,contents->PUID,contents->age);
        
        current=sameOut;
        
        while( current->next!= contents )
        {
            current = current->next;
        }
        
        contents=current;
        
        
    }
  
    
}

//EmptyStack
void EmptyStack()
{
    struct student *one, *two;
    
    one=head;
    while(one!=NULL)
    {
        two=one->next;
        pop();
        one=two;
    }
    if(one==NULL)
    {
        printf("It has been emptied!");
    }
}

//traverseStack
void traverseStack()
{
    current=head;
    
    while( current != NULL )
    {
        current = current->next;
    }
}



//Queue

//Enqueue
void Enqueue(struct student *new)
{
    if(new==(struct student *) NULL)
    {
        printf("\n Failed to allocate memory for this stack.");
        exit(1);
    }
    
    if(out==NULL)
    {
        out=new;
        sameOut=new;
    }
    if(in!=NULL)
    {
        in->next=new;
    }
    
    new->next=NULL;
    in=new;
    
}

//Dequeue
void Dequeue()
{
    struct student *temp;
    
    temp=out->next;
    out=NULL;
    out=temp;
}

//EmptyQueue
void EmptyQueue()
{
    struct student *one, *two;
    
    one=out;
    while(one!=NULL)
    {
        two=one->next;
        Dequeue();
        one=two;
    }
    if(one==NULL)
    {
        printf("It has been emptied!");
    }
}


//PrintQueue
void PrintQueue()
{
    struct student *contents;
    
    contents=out;
    printf("Information: \n");
    
    while(contents!=NULL)
    {
        printf("%s\t %s\t %s\t %d\n",contents->firstName,contents->lastName,contents->PUID,contents->age);
        contents=contents->next;
    }
}

//traverseQueue
void traverseQueue()
{
    current=out;
    
    while( current != NULL )
    {
        current = current->next;
    }
}

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
    printf("\n\nThis program handles nodes in structs, please choose a tool:\n");
    printf("\t1. Add a node\t2.Empty Queue\n");
    printf("\t3. Empty Stack\t4. Print Queue\n");
    printf("\t5. Print Stack\t6. Exit!\n");
    printf("Please make a choice [1-6]: ");
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
            return 5;  // Return 5, the menu option selected
            break;
        case 6:
            return 6;  // Return 6, the menu option selected
            break;
        default:
            printf("\n\nThat choice was invalid.  Please choose a valid menu item, values 1 throuh 6 are acceptable.\n\n");
            // Clear scan flag
            clean_stdin();
            return 0;  // Return 0 as an error code for no proper selection.
            break;
    }
}

int loopMenu()
{
    char firstName[10];
    char lastName[10];
    char PUID[10];
    int age;
    
    //char oldPUID[10];
    struct student *new, *sameNew;
    new = (struct student *) malloc( sizeof(struct student) );
    
    /* A value to hold the menu item chosen */
    int menuChoice = 0;
    /* Show the main menu for user selection */
    while(writeMenu(&menuChoice)==0);
    
    /* User has made a decision at this point, run switch case */
    printf("\n");
    switch(menuChoice)
    {
        case 1:
            
            clean_stdin();
            
            printf("Please enter the first name :\n ");
            gets(firstName);
            printf("Please enter the last name :\n ");
            gets(lastName);
            printf("Please enter the PUID :\n ");
            gets(PUID);
            printf("Please enter the age :\n ");
            scanf("%d",&age);
            
            new=AddNode(firstName, lastName, PUID, age);
            sameNew=new;
            push(sameNew);
            Enqueue(new);
            break;
            
        case 2:
            
            EmptyQueue();
            break;
            
        case 3:
            
            EmptyStack();
            break;
            
        case 4:
           
            PrintQueue();
            break;
            
        case 5:
            
            PrintStack();
            
            break;
            
        case 6:
            
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