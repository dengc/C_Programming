/** lab35_main.c: Implements a front end for lab35_lib.c.
 *
 *
 * Name:Chufan Deng
 * Email:dengc@purdue.edu
 * Course: CNIT 315
 * Lab batch:010
 * Lab assignment: 3.5
 * Date:3/2/15
 *
 * Collaborators:
 
 gcc -W -Werror lab35_main.c lab35_lib.c -o lab35_main.o
 ./lab35_main.o
 */

#include <time.h> //for time()
#include <stdlib.h>
#include <stdio.h>

#include "lab3_lib.h"

/**
 * Calls the functions implemented in lab35_lib.c and implements a menu system
 * for them.
 *
 * 	@return 	0 - Successful completion of the program.
 * 				1 - An error during execution.
 */
int main(){
    /* Initialize */
    
    srand(time(NULL));

    /* Menu */
    
    int a;
    int count=0;
    int *firstArray=(int *) malloc(0*sizeof(int));
    
    int y=0;
    int x;

//    printf("Enter the first integer in this array with a size of 3:\n");
//    scanf("%d",&a);
//    
//    firstArray[0]=a;
//    
//    printf("Enter the second integer in this array with a size of 3:\n");
//    scanf("%d",&a);
//    
//    firstArray[1]=a;
//    
//    printf("Enter the third integer in this array with a size of 3:\n");
//    scanf("%d",&a);
//    
//    firstArray[2]=a;
//    
//    printf("Now your array is:\n");
//    for(int b=0;b<=2;b++)
//    {
//        printf("%d\n",firstArray[b]);
//    }
    
    while (y==0){
        printf("Please select one that you would like to do[1-4]: \n");
        printf("1. Add a new value\n");
        printf("2. Sort the array\n");
        printf("3. Search for a paricular value\n");
        printf("4. Exit\n");
        scanf("%d", &x);
        while ((x != 1) && (x != 2) && (x != 3) && (x != 4)){
            printf("Please select one that you would like to do[1-4]: \n");
            printf("1. Add a new value\n");
            printf("2. Sort the array\n");
            printf("3. Search for a paricular value\n");
            printf("4. Exit\n");
            scanf("%d", &x);
        }
        
        
        /* Wrap up */
        
        if (x==1){
            
            count++;
            printf("Enter this number:\n");
            scanf("%d",&a);
            firstArray=(int*) realloc (firstArray, (count)*sizeof(int));
            firstArray[count-1]=a;
            printf("Now your array is:\n");
            for(int b=0;b<=count-1;b++)
            {
                printf("%d\n",firstArray[b]);
            }
            
            continue;
            
        }

        else if (x==2){
        
            int array_sorted[count-1];
            selection_sort(firstArray,count,array_sorted);
            
            printf("Now your sorted array is:\n");
            for(int b=0;b<=count-1;b++)
            {
                printf("%d\n",array_sorted[b]);
            }
            
            continue;
        }
        
        else if (x==3){
            
            printf("Enter a value that you want to search:");
            scanf("%d",&a);
            int location=-1;
            int array_sorted[count-1];
            selection_sort(firstArray,count,array_sorted);
            binary_search(array_sorted,count,a,&location);
            continue;
            
        }

        else{
            
            y = 1;
            printf("Thank you!\n");
            return 0;
        }
        
        return 0;
    }
}

