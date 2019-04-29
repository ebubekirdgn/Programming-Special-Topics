#include <stdio.h>


#define print(x,y) print ## x((y))


void printshort(short a) {
	printf("%hd\n",a);
}
void printint(int a) {
	printf("%d\n",a);
}


int main(void) {
	
	int a=2;
	short b=4;
	
	print(int ,a);
	print(short ,b);
	return 0;
}
