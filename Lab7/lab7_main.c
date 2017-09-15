/**
 *
 * Name:Chufan Deng
 * Email:dengc@purdue.edu
 * Course: CNIT 315
 * Lab batch:010
 * Lab assignment: 7
 * Date:4/20/15
 *
 * Collaborators:
 gcc -W -Werror lab7_main.c -o lab7_main.o
 ./lab7_main.o

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//CreateTree0()
struct node *root;
struct node *leaf;

//CreateTree1()
struct node *CreateTree1(int i)
{
    struct node *new;
    
    new = (struct node *) malloc( sizeof(struct node) );
    
    new->data = i;
    new->left = NULL;
    new->right= NULL;
    
    return(new);
}


//AddNode(Node)
void AddNode1(struct node *new)
{
    //struct node *leaf;
    leaf=root;
    
    while(1)
    {
        if(new->data<=leaf->data)
        {
            if(!(leaf->left))
            {
                leaf->left = new;
                return;
            }
            leaf=leaf->left;
        }
        else
        {
            if(!(leaf->right))
            {
                leaf->right = new;
                return;
            }
            leaf=leaf->right;
        }
    }
    
}

//AddNode(int)
void AddNode2(int i)
{
    //struct node *leaf;
    leaf=root;
    
    while(1)
    {
        if(i<=leaf->data)
        {
            if(!(leaf->left))
            {
                leaf->left = CreateTree1(i);
                return;
            }
            leaf=leaf->left;
        }
        else
        {
            if(!(leaf->right))
            {
                leaf->right = CreateTree1(i);
                return;
            }
            leaf=leaf->right;
        }
    }
}


int traverse(struct node * tree)
{
    int i=0;
    if(tree)
    {
        i=tree->data;
    }
    return i;
}


/*
//DeleteNode(int)
//(in-order successor)
void DeleteNode(int i)
{
    struct node *temp=NULL;

    //struct node *leaf;
    leaf=root;
*
    while(1)
    {
        if(i==root->data)
        {
            if(root->right==NULL&&root->left==NULL)
            {
                root=NULL;
            }
            else if(root->right==NULL)
            {
                root=root->left;
            }
            else if(root->right->left==NULL)
            {
                temp=root->left;
                root=root->right;
                root->left=temp;
            }
            else
            {
                root->data=root->right->left->data;
                root->right->left=root->right->left->right;
            }
            printf("It has been deleted!");
            break;
        }
        else if(i>root->data)
        {
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }

    while(1)
    {
        if(leaf==NULL)
        {
            printf("No node found!");
            return;
        }
        
        else if(i>traverse(leaf))
        {
            leaf=leaf->right;
        }
        else if(i<traverse(leaf))
        {
            leaf=leaf->left;
        }
        
        else
        {
            if(leaf->right==NULL&&leaf->left==NULL)
            {
                leaf=NULL;
            }
            else if(leaf->right==NULL)
            {
                leaf->data=leaf->left->data;
            }
            else
            {
                leaf->data=Min(leaf->right)->data;
              
                temp=Min(leaf->right)->right;
                temp=Min(leaf->right);
            }
            printf("It has been deleted!");
            break;
        }
    }
}
*/


struct node * FindMin(struct node *node)
{
    if(node==NULL)
    {
        /* There is no element in the tree */
        return NULL;
    }
    if(node->left) /* Go to the left sub tree to find the min element */
        return FindMin(node->left);
    else
        return node;
}


struct node * Delete(struct node *node, int data)
{
    struct node *temp;
    if(node==NULL)
    {
        printf("Element Not Found");
    }
    else if(data < node->data)
    {
        node->left = Delete(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Delete(node->right, data);
    }
    else
    {
      
        if(node->right && node->left)
        {
            
            temp = FindMin(node->right);
            node -> data = temp->data;
            
            node -> right = Delete(node->right,temp->data);
        }
        else
        {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
    
}


//TraverseFind(int)
bool TraverseFind(int i)
{
    leaf=root;
    
    while(1)
    {
        if(leaf==NULL)
        {
            return false;
        }
        else if(i>traverse(leaf))
        {
            leaf=leaf->right;
        }
        else if(i<traverse(leaf))
        {
            leaf=leaf->left;
        }
        else
        {
            return true;
        }
    }
    
}


//TraversePrint
void TraversePrint(struct node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        TraversePrint(tree->left);
        TraversePrint(tree->right);
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
    printf("\t1. Enter the first node(int) in a tree (You have to do that first!!) \n \t2. Add a node \n");
    printf("\t3. Add a node (int)\n\t4. Delete a node (int)\n");
    printf("\t5. Check if it is found (int) \n\t6. Print all the value. \n");
    printf("\t7. Exit!\n");
    printf("Please make a choice [1-7]: ");
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
        default:
            printf("\n\nThat choice was invalid.  Please choose a valid menu item, values 1 throuh 7 are acceptable.\n\n");
            // Clear scan flag
            clean_stdin();
            return 0;  // Return 0 as an error code for no proper selection.
            break;
    }
}

int loopMenu()
{
    int data;
   
    struct node *new=NULL;
   
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
            
            printf("Please enter the fisrt node (int) :\n ");
            scanf("%d",&data);
            
            root=CreateTree1(data);
        
            break;
            
        case 2:
            
            clean_stdin();
            
            printf("Please add a node (int) :\n ");
            scanf("%d",&data);
            
            new=CreateTree1(data);
            AddNode1(new);
            break;

            
        case 3:
            
            clean_stdin();
            
            printf("Please add a node (int) :\n ");
            scanf("%d",&data);
       
            AddNode2(data);
            break;
            
        case 4:
            
            clean_stdin();
            
            printf("Please delete a node (int) :\n ");
            scanf("%d",&data);
            
            //DeleteNode(data);
            root=Delete(root,data);
            break;
            
        case 5:
            
            clean_stdin();

            printf("Please enter a number to check if it is in the tree :\n ");
            scanf("%d",&data);
            
            if(TraverseFind(data)==true)
            {
                printf("Yes!");
            }
            else
            {
                printf("No!");
            }
            
            break;
            
        case 6:

            TraversePrint(root);
            break;
            
        case 7:
            printf("Closing program!\n\n");
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