#include <stdio.h>
#include <stdlib.h>
#include "matarith.h"
#include "matarith.h"

#pragma pack(5) 
//Fazladan boþluk ekleme olayýný yapmýyor bunu ekleyince 
typedef struct
{
	//https://stackoverflow.com/questions/3318410/pragma-pack-effect
	// char | 1 |
	// int  | 1 | 2 | 3 | 4 |
	
	//Pack 1 için 
	// | 1 | -> char
	// | 1 | -> int
	// | 2 | -> int
	
	//Pack 2 için 
	// | 1 | 2 | -> char
	// | 1 | 2 |-> int
	// | 3 | 4 |-> int
	
      char c; //20
	  long long int  a; //20 byte yer kaplar. + 2 byteda  |a _ _| , eðer |aa |_ _ _ _| þeklinde olacaktýr
}uni_t,uni[1];


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void print_array(int *m,int uzunluk)
{
	int i;
	for(i=0;i<uzunluk;i++)
	{
		printf("%d-",m[i]);
	}
	
}

/////////////////////////////////////////////////////////////


#pragma startup School 105
#pragma startup College
#pragma exit College
#pragma exit School 105

void School(){
printf("\nI am in School");

}

void College(){
printf("\nI am in College");

}

/////////////////////////////////////////////////////////////


int main(int argc) {
/*	int m1[] = {3,5};
	int m2 [] = {1,2};
	int m3[] = {{1},{2}};
	int outMatrix[] = {0,0};
	
	printf("Toplam : ");
	matrix_add(outMatrix,m1,m2,1,1);
	print_array(outMatrix,1);
	printf("\n");
	
	printf("Carpim : ");
	matrix_mul(outMatrix,m1,m3,1,2,1);
	print_array(outMatrix,1);
	printf("\n");
	 
	printf("Cikarma : ");
	matrix_sub(outMatrix,m1,m2,1,1);
	print_array(outMatrix,1);
	printf("\n");
	*/
	
	uni_t a;
	uni b;
	printf("%d\t%d\n",sizeof(a),sizeof(b));
	return 0;
}
