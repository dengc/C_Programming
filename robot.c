#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    motor(0, 100);
    motor(2, 100);
    msleep(26000);
    ao();

    motor(0, 100);
    msleep(1000);
    ao();

    msleep(3000);
    ao();
   
    return 0;
}
