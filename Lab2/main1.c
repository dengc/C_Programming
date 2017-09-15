/*
 * Name: Chufan Deng
 * Email: dengc@purdue.edu
 * Course: CNIT 315
 * Session: 010
 * Lab batch: 2
 * Lab assignment: 2
 * Date: 7 February 2015
 *
 gcc -W -Werror main1.c fac.c fib.c hanoi.c -o main1.o
 ./main1.o
 */

#include<stdio.h>
#include"fac.h"
#include"fib.h"
#include"hanoi.h"


int main(){
    int x;
    int n;
    int m;
    int h;
    int y = 0;
    char a='a';
    char b='b';
    char c='c';
    
    while (y == 0){
        printf("Please select one that you would like to do calculation[1-4]: \n");
        printf("1. Factorial\n");
        printf("2. Fibonacci\n");
        printf("3. Hanoi\n");
        printf("4. Exit\n");
        scanf("%d", &x);
        while ((x != 1) && (x != 2) && (x != 3) && (x != 4)){
            printf("Please select an integer number from 1 to 4!\n");
            printf("1. Factorial\n");
            printf("2. Fibonacci\n");
            printf("3. Hanoi\n");
            printf("4. Exit\n");
            scanf("%d", &x);
        }
        
        
        if (x==1){
            printf("Enter a positive integer to calculate factorial:");
            scanf("%d", &n);
            while (n < 0){
                printf("It is a negative number!\n");
                printf("Enter a positive integer to calculate factorial:");
                scanf("%d", &n);
            }
            printf("The factorial of the number is %d.\n", fac(n));
            continue;
        }
        
        else if (x==2){
            printf("Enter a positive number for finding in Fibonacci :");
            scanf("%d", &m);
            while (m < 0){
                printf("It is a negative number!\n");
                printf("Enter a positive number for finding in Fibonacci :");
                scanf("%d", &m);
            }
            printf("The number in the Fibonacci is %d.\n", fib(m));
        }
        
        else if (x==3){
            printf("Enter a positive number of disks for playing Towers of Hanoi:");
            scanf("%d", &h);
            while (h < 0){
                printf("It is a negative number!\n");
                printf("Enter a positive number of disks for playing Towers of Hanoi:");
                scanf("%d", &h);
            }
            printf("%c, %c, %c \n", a, b, c);
            run_hanoi(h, a, b, c);
        }
        
        else{
            y = 1;
            printf("Thank you!\n");
            return 0;
        }
    }
    
    return 0;
}

