#include <stdio.h>
#include <stdlib.h>
#include "matarith.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void print_array(int *m,int uzunluk)
{
	int i;
	for(i=0;i<uzunluk;i++)
	{
		printf("%d-",m[i]);
	}
	
}
int main(int argc) {
	int m1[] = {4,1};
	int m2[] = {4,2};
	int outMatrix[] = {0,0};
	
	printf("Toplam : ");
	matrix_add(outMatrix,m1,m2,1,1);
	print_array(outMatrix,4);
	printf("\n");
	
	printf("Carpim : ");
	matrix_mul(outMatrix,m1,m2,1,1,1);
	print_array(outMatrix,4);
	printf("\n");
	 
	printf("Cikarma : ");
	matrix_sub(outMatrix,m1,m2,1,1);
	print_array(outMatrix,4);
	printf("\n");
	
	return 0;
}

