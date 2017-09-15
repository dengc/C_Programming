/** lab3_main.c: Implements a front end for lab3_lib.c.
 *
 *
 * Name:Chufan Deng
 * Email:dengc@purdue.edu
 * Course: CNIT 315
 * Lab batch:010
 * Lab assignment: 3
 * Date:2/22/15
 *
 * Collaborators:
 gcc -c lab3_lib.c
 gcc lab3_lib.o lab3_tests.o -o lab3_tester.out
 ./lab3_tester.out 2> results.txt
 gedit results.txt
 
 gcc -W -Werror lab3_main.c lab3_lib.c -o lab3_main.o
 ./lab3_main.o
 */

#include <time.h> //for time()
#include <stdlib.h>
#include <stdio.h>

#include "lab3_lib.h"

/**
 * Calls the functions implemented in lab3_lib.c and implements a menu system
 * for them.
 *
 * 	@return 	0 - Successful completion of the program.
 * 				1 - An error during execution.
 */
int main(){
    /* Initialize */
    
    srand(time(NULL));
    
    void bubble(int);
    void selection(int);
    void insertion(int);
    void linear(int);
    void binary(int);
    
    /* Menu */
    
    
    int y=0;
    int x;
    int i;
    int value;
   
    
	double sortTime;
	clock_t time;

    while (y==0){
        printf("Please select one that you would like to do[1-6]: \n");
        printf("1. Bubble sort\n");
        printf("2. Selection\n");
        printf("3. Insertion\n");
        printf("4. Linear search\n");
        printf("5. Binary search\n");
        printf("6. Exit\n");
        scanf("%d", &x);
        while ((x != 1) && (x != 2) && (x != 3) && (x != 4)&&(x!=5)&&(x!=6)){
            printf("Please select one that you would like to do[1-6]: \n");
            printf("1. Bubble sort\n");
            printf("2. Selection\n");
            printf("3. Insertion\n");
            printf("4. Linear search\n");
            printf("5. Binary search\n");
            printf("6. Exit\n");
            scanf("%d", &x);
        }
        
        
        /* Wrap up */
        
        if (x==1){
            
            time=clock();
            bubble(10);
			time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("10 takes %f\n", sortTime);

			time=clock();
			bubble(50);
			time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("50 takes %f\n", sortTime);

			time=clock();
			bubble(100);
			time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("100 takes %fs\n", sortTime);

			time=clock();
			bubble(500);
            time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("500 takes %f\n", sortTime);

			time=clock();
			bubble(1000);
            time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("1000 takes %f\n", sortTime);

			time=clock();
			bubble(5000);
			time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("5000 takes %f\n", sortTime);

			time=clock();
			bubble(10000);
            time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("10000 takes %f\n", sortTime);

			time=clock();
			bubble(15000);
			time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("15000 takes %f\n", sortTime);

			time=clock();
			bubble(20000);
			time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("20000 takes %f\n", sortTime);

            continue;
            
        }

        else if (x==2){

            time=clock();
            selection(10);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("10 takes %f\n", sortTime);
            
            time=clock();
            selection(50);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("50 takes %f\n", sortTime);
            
            time=clock();
            selection(100);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("100 takes %fs\n", sortTime);
            
            time=clock();
            selection(500);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("500 takes %f\n", sortTime);
            
            time=clock();
            selection(1000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("1000 takes %f\n", sortTime);
            
            time=clock();
            selection(5000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("5000 takes %f\n", sortTime);
            
            time=clock();
            selection(10000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("10000 takes %f\n", sortTime);
            
            time=clock();
            selection(15000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("15000 takes %f\n", sortTime);
            
            time=clock();
            selection(20000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("20000 takes %f\n", sortTime);
            
            continue;
        }
        
        else if (x==3){
            
            time=clock();
            insertion(10);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("10 takes %f\n", sortTime);
            
            time=clock();
            insertion(50);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("50 takes %f\n", sortTime);
            
            time=clock();
            insertion(100);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("100 takes %fs\n", sortTime);
            
            time=clock();
            insertion(500);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("500 takes %f\n", sortTime);
            
            time=clock();
            insertion(1000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("1000 takes %f\n", sortTime);
            
            time=clock();
            insertion(5000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("5000 takes %f\n", sortTime);
            
            time=clock();
            insertion(10000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("10000 takes %f\n", sortTime);
            
            time=clock();
            insertion(15000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("15000 takes %f\n", sortTime);
            
            time=clock();
            insertion(20000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("20000 takes %f\n", sortTime);
            
            continue;
            
        }

        else if(x==4){
            
			time=clock();
            linear(10);
			time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("10 takes %f\n", sortTime);

            time=clock();
            linear(50);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("50 takes %f\n", sortTime);
            
            time=clock();
            linear(100);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("100 takes %fs\n", sortTime);
            
            time=clock();
            linear(500);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("500 takes %f\n", sortTime);
            
            time=clock();
            linear(1000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("1000 takes %f\n", sortTime);
            
            time=clock();
            linear(5000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("5000 takes %f\n", sortTime);
            
            time=clock();
            linear(10000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("10000 takes %f\n", sortTime);
            
            time=clock();
            linear(15000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("15000 takes %f\n", sortTime);
            
            time=clock();
            linear(20000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("20000 takes %f\n", sortTime);
            
            continue;
            //linear_search
        }
        
        else if(x==5)
        {
			time=clock();
            binary(10);
			time=clock()-time;
			sortTime=((double)time)/CLOCKS_PER_SEC;
			printf("10 takes %f\n", sortTime);

            time=clock();
            binary(50);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("50 takes %f\n", sortTime);
            
            time=clock();
            binary(100);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("100 takes %fs\n", sortTime);
            
            time=clock();
            binary(500);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("500 takes %f\n", sortTime);
            
            time=clock();
            binary(1000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("1000 takes %f\n", sortTime);
            
            time=clock();
            binary(5000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("5000 takes %f\n", sortTime);
            
            time=clock();
            binary(10000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("10000 takes %f\n", sortTime);
            
            time=clock();
            binary(15000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("15000 takes %f\n", sortTime);
            
            time=clock();
            binary(20000);
            time=clock()-time;
            sortTime=((double)time)/CLOCKS_PER_SEC;
            printf("20000 takes %f\n", sortTime);
            
            continue;
            //binary_search
        }

        else{
            y = 1;
            printf("Thank you!\n");
            return 0;
        }
        
        return 0;
    }
}

void bubble(int size)
{
    int random[size];
    generate_random_int_array(random, size);
    int array_sorted[size];
    bubble_sort(random,size,array_sorted);
    
}

void selection(int size)
{
    int random[size];
    generate_random_int_array(random, size);
    int array_sorted[size];
    selection_sort(random,size,array_sorted);
}

void insertion(int size)
{
    int random[size];
    generate_random_int_array(random, size);
    int array_sorted[size];
    insertion_sort(random,size,array_sorted);
}

void linear(int size)
{
    int random[size];
    generate_random_int_array(random, size);
    int value=rand();
    int location=-1;
    linear_search(random,size,value,&location);
}

void binary(int size)
{
    int random[size];
    generate_random_int_array(random, size);
    int value=rand();
    int location=-1;
    binary_search(random,size,value,&location);
}

