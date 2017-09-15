#include<stdio.h>
#include"hanoi.h"

void run_hanoi(int a, char from, char to, char spare){

	if(a==1){

		printf("It moves from %c to %c\n", from, to);
		return;

	}

	run_hanoi(a-1,from,spare,to);
	run_hanoi(1,from,to,spare);
	run_hanoi(a-1,spare,to,from);
}
