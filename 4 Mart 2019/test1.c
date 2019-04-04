#include <stdio.h>
#include <x86intrin.h>
#include "../src/matarith.h"
#define N 5

typedef __attribute__((aligned(32))) int mat[N*N];

int main(){
	
	// Array contains 100 elements , matrix 10 * 10
	//int a[] __attribute__((aligned(32))) = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5};
	//int b[] __attribute__((aligned(32))) = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5};
	//int a[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5};
	//int b[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5};
	mat  a = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5};
	mat  b = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5,1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2,3,4,5,6,7,8,9,10,1,2,3,4,5};
	

	//int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int o[100];
	int a_satir = 5, a_sutun = 5;
	int b_satir = 5, b_sutun = 5;
	int num = 100;
	//matrix_mult( o, a, b, a_satir, a_sutun, b_sutun);
  	//printf("o[0] = %d",o[0]);
  	//matrix_mult(o, a, b,)
	
	int i;
	unsigned long long avg = 0;
        long long int c[2000];
        for(i = 0; i < 1000; i++){
        	c[i*2 + 0] = _rdtsc();	
		matrix_mult( o, a, b, a_satir, a_sutun, b_sutun);
		c[i*2 + 1] = _rdtsc();
    	}

	printf("%lld\n", c[2000] - c [0]);
	for (i = 0; i < 1000; i++){
		avg += c[i+ 1] - c[i];
	}
	//printf("AVG_0: %lld\n", c[1] - c[0]);
	printf("Avg: %lld\n", avg/1000);
	//	printf("AVG_0: %lld\n", c[2000] - c[1999]);
	
	return 0;
}
// performans ölçümü ile ilgili kodlardır.
