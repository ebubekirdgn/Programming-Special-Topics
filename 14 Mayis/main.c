#include <stdio.h>
#include <stdlib.h>
#include<x86intrin.h>


// 2^20 * 2 ^20 = 2 ^ 40 tane matris oluþuyor.

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*
	Günümüz iþlemcilerinde hafýza hemen kullanýlmýyor.Önbellek kulllanýrlar.
	
	RAM   -> (2^10 * 2^10 * 4 = 2^22) , (2^12 * 2^12 * 4 = 2^26)
	L3 3 Mb gibi  -> 2^9 * 2^9 * 4 = 2^18
	L2 256 kb civarýnda  -> 2^8 * 2^8 * 4 = 2^18
	L1 sadece 32 kb  -> 2^6 * 2^6 * 4 = 2^14
	CPU
	
	Bu sýra ile en üstten alta dogru iner.
	
	////////////////////////////////////////////
	Çýktýsý #define N (1<<13) için;
	
	124512 (1.00),68 (0.00),171 (0.00);
	122249 (1.00),101 (0.00),403 (0.00);
	242524 (1.00),147 (0.00),1208 (0.00);
	465049 (1.00),464 (0.00),4621 (0.01);
	845059 (1.00),2547 (0.00),16887 (0.02);
	1736042 (1.00),8482 (0.00),65834 (0.04);
	3684838 (1.00),29807 (0.01),258879 (0.07);
	7174000 (1.00),221240 (0.03),1128190 (0.16);
	14268980 (1.00),1108708 (0.08),4199784 (0.29);
	28090996 (1.00),8795544 (0.31),16450846 (0.59);
	55837664 (1.00),36446152 (0.65),66499153 (1.19);
	112572056 (1.00),180512743 (1.60),260702716 (2.32);
	222079842 (1.00),751624782 (3.38),1040508542 (4.69);
	442946284 (1.00),3267124242 (7.38),4158694236 (9.39);	
	
	Burada aradaki sýçramalar bizim tamamen belleðimizin kapasitesi ile alakalýdýr.
 	/////////////////////////////////////////////////////
 
*/



#define N (1<<12)
#define step 8


int main(void) {
	
	//int a[N*N] ,b [N*N],c[N*N];
	int *a , *b , *c;
	a =(int *)malloc(4LL*N*N);
	b =(int *)malloc(4LL*N*N);
	c =(int *)malloc(4LL*N*N);
	
	int i,j,n,k;
	long long int at0,at1,bt0,bt1,ct0,ct1;
	
	
	
	for(n=16;n<=N;n<<=1)
	{
	
	  at0 = _rdtsc();
	  for(k=0;k<16;k++)
	  {
		for(i=0;i<n;i++) //satýr tabanlý eriþim
		{
			for(j=0;j<n;j+=step)
			{
				a[(long long int)i*n+j] =j;
			}
		}
		at1 = (_rdtsc() - at0)>>4;
	  }
	  
		bt0 = _rdtsc();
		for(k=0;k<16;k++)
	    {
			for(i=0;i<n;i+=step)//sütun tabanlý eriþim
			{
				for(j=0;j<n;j++)
				{
					b[(long long int)j*n+i] =i;
				}
			}
			bt1 =( _rdtsc() - bt0)>>4;
	   } 
		
		ct0 = _rdtsc();
		for(k=0;k<16;k++)
	    {
			for(i=0;i<n;i++)//rastgele eriþim
			{
				for(j=0;j<n;j++)
				{
					c[(long long int)(rand()*step)%(n*n)] =j;
				}
			}
			ct1 = (_rdtsc() - ct0)>>4;
	    }
	    printf("%lld (%.2f),%lld (%.2f),%lld (%.2f);\n",at1,(double)at1/at1,bt1,(double)bt1/at1,ct1,(double)ct1/at1);
	}
	//printf("%d,%d,%d;\n",at1,bt1,ct1);
	
	
	return 0;
}
