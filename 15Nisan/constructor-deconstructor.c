#include<stdio.h>  
 
//Yardımcı site : https://www.geeksforgeeks.org/pragma-directive-in-c-c/    

#pragma startup func1  
#pragma exit func2  
    __attribute__((constructor (100)))void func2();
    __attribute__((constructor (99)))void func1();
    __attribute__((destructor))void func2();
    __attribute__((destructor))void func1();
void func1()  
{  
    printf("Inside func1()\n");  
}  
    
void func2()  
{  
    printf("Inside func2()\n");     
}  
    
int main()  
{  
    printf("Inside main()\n");  
        
    return 0;  
} 

//_attributelerin bütün özelliklerini kod örnekleri ile raporla
