#include <stdio.h>
#include <string.h>

unsigned char buff[20] = {0x00};
const unsigned char dp1[] = {0x05, 0x01, 0x02, 0x03, 0x04};
const unsigned char dp2[] = {0xff, 0x02, 0x02, 0x02, 0x02};


void main()
{

	int i = 0;
	int j = 0;
	memset(buff, 0, 20);
	for(i=0; i<20; i++)
	{
		printf("%x ",buff[i]);
	}
	printf("\n");printf("\n");printf("\n");

	strcat(buff, dp1);
	for(i=0; i<20; i++)
	{
		printf("%x ",buff[i]);
	}
	printf("\n");printf("\n");printf("\n");


	strcat(buff, dp2);
	for(i=0; i<20; i++)
	{
		printf("%x ",buff[i]);
	}
	printf("\n");printf("\n");printf("\n");

	printf("%d\n", i);

}


void test(void)
{
	int num = 32768;
	int i = 0;
	int j = 0;
	while(i<32768)
	{
		i++;
		if(num%i == 0)
		{
			printf("%d\n", i);
		}
	}
	printf("\n");
}