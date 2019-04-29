#include <stdio.h>
#include <limits.h>

int main(void){
	short int i;
	int counter = 0;
	for(i = SHRT_MIN; i < SHRT_MAX; i++){
			counter++;
	 }
	printf("%d\n", counter);
	
	
	#ifdef __linux
		printf("Linux");
	#else
		printf("Other");
	#endif
	return 0;
} 

