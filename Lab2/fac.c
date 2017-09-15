#include"fac.h"

int fac(int n){

	if(n==1){

	return 1;
	}

	if(n==0){

	return 1;
	}

	return n*fac(n-1);
}
