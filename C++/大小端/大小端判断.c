
#include<stdio.h>
void main()
{
	unsigned short i=0xaaf2; 
	unsigned char *p=(char *)&i; 

	if(*p==0xf2) 
	{
		printf("Little Endian\n"); 
		printf("*p = %x\n", *p);
		printf("*(p+1) = %x\n", *(p+1));
		
	}
	else
	{
		printf("Big Endian\n");
		printf("*p = %x\n", *p);
		printf("*(p+1) = %x\n", *(p+1));
	}
}