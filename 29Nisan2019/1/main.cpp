#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {
	
	#IF LONG__MAX == LONGLONG__MAX
	
		typedef long int mylong;
	
	#ELSE
	
	 typedef long long int mylong;
	
	#ENDIF
 
	return 0;
}
