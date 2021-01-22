#include <stdio.h>
#include <string.h>

unsigned long num0 = 65534;
unsigned long num1 = 0;
unsigned char num_bit0[4] = {0};
unsigned char num_bit1[4] = {0};

void main()
{

	int i = 0;
	int j = 0;

	*((unsigned long *)num_bit0) = num0;
	for(i=0; i<4; i++)
	{
		printf("%d ",num_bit0[i]);
	}
	printf("\n");printf("\n");printf("\n");

	memcpy(num_bit1, num_bit0, 4);

	num1 = *(unsigned long *)num_bit1;

	printf("%d\n\n",num1);

}

