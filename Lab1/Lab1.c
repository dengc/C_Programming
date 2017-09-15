/*
 * Name: Chufan Deng
 * Email: dengc@purdue.edu
 * Course: CNIT 315
 * Lab batch: -1
 * Lab assignment: 1
 * Date: 3 February 2015
 *
 *gcc -W -Werror Lab1.c -o Lab1.o
 ./Lab1.o
 */

#include<stdio.h>



int main(){
    
    char answer;
    
    double depthOfShallow;
    double depthOfDeep;
    double widthOfPool;
    double lengthOfPool;
    double lengthOfWalkin;
    double lengthOfShallow;
    double lengthOfDeep;
    double widthOfHottub;
    double depthOfHottub;
    
    double lWI;
    double lS;
    double lD;
    
    double volumeOfHottub;
    double volumeOfPool;
    
    double waterInPool;
    double waterInHottub;
    
    double totalGallon;
    
    double totalCost;
    
    double check=0;
    
    while(check==0){
        
        printf("Please enter the Depth of the shallow end (2 - 5 feet):");
        scanf("%lf",&depthOfShallow);
        if(depthOfShallow<2.0||depthOfShallow>5.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 2 AND 5 FEET!");
            
            return 1;
        }
        
        printf("Please enter the Depth of the deep end (6 - 12 feet):");
        scanf("%lf",&depthOfDeep);
        if(depthOfDeep<6.0||depthOfDeep>12.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 6 AND 12 FEET!");
            
            return 2;
        }
        
        printf("Please enter the Width of the pool (15 - 30 feet):");
        scanf("%lf",&widthOfPool);
        if(widthOfPool<15.0||widthOfPool>30.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 15 AND 30 FEET!");
            
            return 3;
        }
        
        printf("Please enter the Length of the pool:  (35 - 60 feet):");
        scanf("%lf",&lengthOfPool);
        if(lengthOfPool<35.0||lengthOfPool>60.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 35 AND 60 FEET!");
            
            return 4;
        }
        
        lWI=lengthOfPool/3.0;
        printf("Please enter the length of the walk in:  (5 -  %.1f):",lWI);
        scanf("%lf",&lengthOfWalkin);
        if(lengthOfWalkin<5.0||lengthOfWalkin>lengthOfPool/3.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 5 AND 1/3 of the pool lengt!");
            
            return 5;
        }
        
        lS=lengthOfPool/3.0;
        printf("Please enter the length of the shallow end: (10 -  %.1f):",lS);
        scanf("%lf",&lengthOfShallow);
        if(lengthOfShallow<10.0||lengthOfShallow>lengthOfPool/3.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 10 AND 1/3 of the pool lengt!");
            
            return 6;
        }
        
        lD=lengthOfPool/2.0;
        printf("Please enter the length of the deep end: (12 -  %.1f):",lD);
        scanf("%lf",&lengthOfDeep);
        if(lengthOfDeep<12.0||lengthOfDeep>lengthOfPool/2.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 12 AND 1/2 of the pool lengt!");
            
            return 7;
        }
        
        printf("Please enter the Width of the hot tub (8 - 14 feet):");
        scanf("%lf",&widthOfHottub);
        if(widthOfHottub<8.0||widthOfHottub>14.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 8 AND 14 FEET!");
            
            return 8;
        }
        
        printf("Please enter the depth of the hot tub (3 - 5 feet):");
        scanf("%lf",&depthOfHottub);
        if(depthOfHottub<3.0||depthOfHottub>5.0)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, PLEASE ENTER A VALUE BETWEEN 3 AND 5 FEET!");
            
            return 9;
        }
        
        if(lengthOfPool<lengthOfWalkin+lengthOfShallow+lengthOfDeep)
        {
            printf("ERROR: THAT IS AN INCORRECT ENTRY, BECAUSE THE LENGTHS OF THE INPUTS ARE LARGER THEN THE LENGTH OF THE POOL!");
            
            return 10;
        }
        
        volumeOfPool=((depthOfDeep-0.5)*lengthOfDeep+(lengthOfPool-lengthOfDeep-lengthOfShallow-lengthOfWalkin)*(depthOfShallow+depthOfDeep-1)/2+lengthOfShallow*(depthOfShallow-0.5)+(depthOfShallow-0.5)*(lengthOfWalkin/depthOfShallow)*(depthOfShallow-0.5)/2)*widthOfPool;
        
        waterInPool=volumeOfPool*7.481;
        
        volumeOfHottub= 3.14*(widthOfHottub/2)*(widthOfHottub/2)*(depthOfHottub-0.5);
        
        waterInHottub= 3.14*(widthOfHottub/2)*(widthOfHottub/2)*(depthOfHottub-0.5)*7.481;
        
        printf("\nvolumeOfPool= %.1f \n",volumeOfPool);
        printf("\nwaterInPool= %.1f \n",waterInPool);
        
        printf("\nvolumeOfHottub= %.1f \n",volumeOfHottub);
        printf("\nwaterInHottub= %.1f \n",waterInHottub);
        
        totalGallon=waterInPool+waterInHottub;
        
        printf("\ntotalGallon= %.1f \n",totalGallon);
        
        totalCost=totalGallon*0.1;
        
        printf("\ntotalCost= %.1f \n\n",totalCost);
        
        check=1;
        
        printf("Do you want to calculate another pool?(Y or N):\n");
        scanf(" %c",&answer);
        if(answer=='Y'){
            
            check =0;
        }
        
    }
    
    return 0;
}



