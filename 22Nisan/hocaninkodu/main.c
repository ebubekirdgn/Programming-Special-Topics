#include <stdlib.h>
#include <stdio.h>

#define push(a,x) *(++a)=x
#define pop(a) *(a--)

int tasi(char **si,char **sj)
{
	if(*(si)!=255 && *((*sj)+1)!=255)
	{
		push((*sj),pop((*si)));
		return 0;			
	}
	return 1;
}

int main(void) {
	char *s0=(char*)malloc(5);
	char *s1=(char*)malloc(5);
	char *s2=(char*)malloc(5);
	
	*s0 =*(s0+4)=255;
	*s1 =*(s1+4)=255;
	*s2 =*(s2+4)=255;
 
	push(s0,'a');
	push(s0,'b');	
	push(s0,'c');		
 
	tasi(&s0,&s2);
	tasi(&s0,&s1);
	tasi(&s2,&s1);
	tasi(&s0,&s2);
	tasi(&s1,&s0);
	tasi(&s1,&s2);
	tasi(&s0,&s2);
	
	int i;
	for(i=0;i<3;i++)
		printf("%c\n",*(s2--));
 	return 0;
}

