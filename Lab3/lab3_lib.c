/** lab3_lib.c: implements sorting and searching functions.
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
 *
 */

#include <stdio.h>
#include <string.h> //for memcpy
#include <stdlib.h>

#include "lab3_lib.h"


/*
 * Pro-tip: use this function to copy arrays.
 */
void deep_copy_array(int* array_from, int* array_to, int array_length){
    //Read more about memcpy over here: http://www.cplusplus.com/reference/cstring/memcpy/
    memcpy(array_to, array_from, array_length*sizeof(int));
}


/*
 * Pro-tip:use this function to generate random arrays.
 */
int generate_random_int_array(int* array, int array_length){
    /* Initialize */
    int i;
    /* Validate input */
    if(!array){
        printf("Error: Input array was NULL\n");
        return 1;
    }
    if(array_length < 1){
        printf("Error: required array size < 1\n");
        return 1;
    }
    /* Generate random values */
    for (i = 0; i < array_length; i++) {
        array[i] =rand()%100;
    }
    return 0;
}


int bubble_sort(int* array_unsorted, int array_length, int* array_sorted){
    /* Initialize */
    
    int c,d, swap;
    int array[array_length];

    
    /* Validate input */
    if(!array_unsorted){
        printf("Error: Unsorted array was NULL\n");
        return 1;
    }
    if(array_length < 1){
        printf("Error: unsorted array size < 1\n");
        return 1;
    }
    if(array_sorted == NULL){
        printf("Error: sorted array is NULL\n");
        return 1;
    }
    /* Sort array */
    deep_copy_array(array_unsorted, array, array_length);

    for(c=0;c<array_length;c++){
        for(d=0;d<array_length-c;d++){
            if(array[d]>array[d+1]){
                swap=array[d];
                array[d]=array[d+1];
                array[d+1]=swap;
            }
        }
    }
    
    deep_copy_array(array, array_sorted, array_length);
    return 0;
}


int selection_sort(int* array_unsorted, int array_length, int* array_sorted){
    /* Initialize */
    int c,d,p, swap;
    int array[array_length];
    
  
    /* Validate input */
    if(!array_unsorted){
        printf("Error: Unsorted array was NULL\n");
        return 1;
    }
    if(array_length < 1){
        printf("Error: unsorted array size < 1\n");
        return 1;
    }
    if(array_sorted == NULL){
        printf("Error: sorted array is NULL\n");
        return 1;
    }
    /* Sort array */
    deep_copy_array(array_unsorted, array,  array_length);

    for ( c = 0 ; c < array_length; c++ )
    {
        p = c;
        
        for ( d = c + 1 ; d < array_length ; d++ )
        {
            if ( array[p] > array[d] )
                p = d;
        }
        if ( p != c )
        {
            swap = array[c];
            array[c] = array[p];
            array[p] = swap;
        }
    }
    
    deep_copy_array(array, array_sorted, array_length);
    
    return 0;
}

int insertion_sort(int* array_unsorted, int array_length, int* array_sorted){
    /* Initialize */
    
    int c,d,t;
    int array[array_length];
    
    
    /* Validate input */
    if(!array_unsorted){
        printf("Error: Unsorted array was NULL\n");
        return 1;
    }
    if(array_length < 1){
        printf("Error: unsorted array size < 1\n");
        return 1;
    }
    if(array_sorted == NULL){
        printf("Error: sorted array is NULL\n");
        return 1;
    }
    /* Sort array */
    deep_copy_array(array_unsorted, array, array_length);

    for (c = 1 ; c <array_length; c++) {
        d = c;
        
        while ( d > 0 && array[d] < array[d-1]) {
            t          = array[d];
            array[d]   = array[d-1];
            array[d-1] = t;
            
            d--;
        }
    }
    
    deep_copy_array(array, array_sorted, array_length);
    
    return 0;
}

int linear_search(int* array1, int array_length, int value, int* location){
    /* Initialize */
    
    int c;
    int array[array_length];
    
    /* Validate input */
    if(!array1){
        printf("Error: array pointer is NULL\n");
        return 1;
    }
    if(array_length < 1){
        printf("Error: array size < 1\n");
        return 1;
    }
    if(!location){
        printf("Error: location variable is NULL\n");
        return 1;
    }
    /* Search array */
    deep_copy_array( array1,  array, array_length);
    
    for (c = 0; c < array_length; c++)
    {
        if (array[c] == value)
        {
            *location=c;
            printf("%d is present at location %d.\n", value, *location);
            break;
        }
    }
    

    return 0;
}

/*
 * You will have to implement this entire function! Remember to check for
 * input errors like the other functions.
 */
int binary_search(int* array2, int array_length, int value, int* location){
    /* Initialize */
    
    int c, first, last, middle;
    int array[array_length];
    
    /* Validate input */
    if(!array2){
        printf("Error: array pointer is NULL\n");
        return 1;
    }
    if(array_length < 1){
        printf("Error: array size < 1\n");
        return 1;
    }
    if(!location){
        printf("Error: location variable is NULL\n");
        return 1;
    }
    /* Search array */
    deep_copy_array( array2, array, array_length);
    
    first = 0;
    last = array_length - 1;
    middle = (first+last)/2;
    
    while( first <= last )
    {
        if ( array[middle] < value )
            first = middle + 1;
        else if ( array[middle] == value )
        {
            *location=middle;
            printf("%d found at location %d.\n", value, *location);
            break;
        }
        else
            last = middle - 1;
        
        middle = (first + last)/2;
    }
    if ( first > last ){
        printf("Not found! %d is not present in the list.\n", value);

    }
    
    return 0;
}
