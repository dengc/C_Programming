/**
 *
 * Name:Chufan Deng
 * Email:dengc@purdue.edu
 * Course: CNIT 315
 * Lab batch:010
 * Lab assignment: 5
 * Date:4/6/15
 *
 * Collaborators:
 gcc -W -Werror lab5_main.c -o lab5_main.o
 ./lab5_main.o

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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



//create_list_node
struct student *create_list_node(char *firstName, char *lastName, char *PUID, int age)
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


//insert_front
void insert_front(struct student *new)
{
    new->next=head;
    head=new;
}

//insert_middle
void insert_middle(struct student *before, struct student *new)
{
    new->next=before->next;
    before->next=new;
}

//insert_end
void insert_end(struct student *new)
{
    new->next=NULL;
    
    struct student *one, *two;
    one= head;
    two= one->next;
    
    while(1)
    {
        if(two-> next==NULL)
        {
            break;
        }
        else
        {
            one=two;
            two=one->next;
        }
    }
    
    two->next=new;
}


//delete_front
void delete_front()
{
    struct student *newHead;
    
    newHead=head;
    head=head->next;
    newHead=NULL;
    
}

//delete_middle
void delete_middle(struct student *before, struct student *new)
{
    before->next=new->next;
    new=NULL;
}

//delete_end
void delete_end()
{
    struct student *one, *two;
    one= head;
    two= one->next;
    
    while(1)
    {
        if(two-> next==NULL)
        {
            break;
        }
        else
        {
            one=two;
            two=one->next;
        }
    }
    
    two=NULL;
    one->next=NULL;
}

//traverse
void traverse()
{
    current=head;
    
    while( current != NULL )
    {
        current = current->next;
    }
}

struct student *traversePUID(char *PUID)
{
    struct student *one;
    one= head;
    
    while (1)
    {
        if(one->next==NULL && *one->PUID!=*PUID)
        {
            return NULL;
        }
        else if(*one->PUID!=*PUID)
        {
            one=one->next;
        }
        else
        {
            return (one);
        }
    }
}


//look_up_by_index
struct student *look_up_by_index(int i)
{
    struct student *one;
    one= head;
    
    int n=0;
    
    while(one!=NULL)
    {
        if(n==i)
        {
            return (one);
            break;
        }
        
        one=one->next;
        n++;
    }
    
    return NULL;
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
    
    head=create_list_node("Jerry", "Deng", "001", 21);
    
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
    printf("\t1. Insert Front\t2. Insert Middle\n");
    printf("\t3. Insert Last\t4. Delete Front\n");
    printf("\t5. Delete Middle\t6. Delete Last\n");
    printf("\t7. Look up the index\t8. Traverse by searching PUID\n");
    printf("\t9. Exit!\n");
    printf("Please make a choice [1-9]: ");
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
        case 7:
            return 7;  // Return 7, the menu option selected
            break;
        case 8:
            return 8;  // Return 8, the menu option selected
            break;
        case 9:
            return 9;
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
    char firstName[10];
    char lastName[10];
    char PUID[10];
    int age;
    
    char oldPUID[10];
    struct student *new;
    struct student *before;
    void display();
    
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
            
            new=create_list_node(firstName, lastName, PUID, age);
           
            insert_front(new);
            display();
            break;
            
        case 2:
            
            clean_stdin();
            
            printf("Please enter the first name :\n ");
            gets(firstName);
            printf("Please enter the last name :\n ");
            gets(lastName);
            printf("Please enter the PUID :\n ");
            gets(PUID);
            printf("Please enter the age :\n ");
            scanf("%d",&age);
            clean_stdin();
            printf("Where do you want to add this? Enter a PUID here: (It will be added next to the struct where this PUID entered is)\n");
            gets(oldPUID);
            //gets(oldPUID);
            new=create_list_node(firstName, lastName, PUID, age);
            
            before=head;
            while(before->next!=NULL)
            {
                if(*before->PUID==*oldPUID)
                {
                    insert_middle(before,new);
                    break;
                }
                else
                {
                    before=before->next;
                }
            }
            
    
            display();
            break;
            
        case 3:
            
            clean_stdin();
            
            printf("Please enter the first name :\n ");
            gets(firstName);
            printf("Please enter the last name :\n ");
            gets(lastName);
            printf("Please enter the PUID :\n ");
            gets(PUID);
            printf("Please enter the age :\n ");
            scanf("%d",&age);
       
            
            new=create_list_node(firstName, lastName, PUID, age);
            insert_end(new);
            display();
            break;
            
        case 4:
            
            delete_front();
            display();
            break;
            
        case 5:
            
            clean_stdin();
            
            printf("Which node do you want to delete? Enter a PUID here: (It will be deleted where this PUID entered is)\n");
            gets(PUID);
            
           
         
            before=head;
            new=before->next;
            
            while(before->next!=NULL)
            {
                if(*new->PUID==*PUID)
                {
                    delete_middle(before,new);
                    break;
                }
                else
                {
                    before=before->next;
                }
            }
            
            display();
            break;
            
        case 6:
            
            delete_end();
            display();
            break;
            
        case 7:
            
            
            clean_stdin();
            int i;
            
            printf("Which node do you want to search? Enter an index here: \n");
            scanf("%d",&i);
            
            new=look_up_by_index(i);
            
            printf("%s\t %s\t %s\t %d\n",new->firstName,new->lastName,new->PUID,new->age);
            
            break;
         
        case 8:
            
            clean_stdin();
            
            printf("Which node do you want to search? Enter the PUID here: \n");
            gets(PUID);
            
            new=traversePUID(PUID);
            
            printf("%s\t %s\t %s\t %d\n",new->firstName,new->lastName,new->PUID,new->age);
            
            break;
            
        case 9:
            printf("\nClosing program!\n");
            exit(0);
            break;
            
    }
    clean_stdin();
    return 1;
}

void display()
{
    struct student *contents;
    
    contents=head;
    printf("Information: \n");
    
    while(contents!=NULL)
    {
        printf("%s\t %s\t %s\t %d\n",contents->firstName,contents->lastName,contents->PUID,contents->age);
        contents=contents->next;
    }
}

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}