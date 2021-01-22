#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char buff1[] = "aaAaaBBBBcBbbbgggFFGGFfff";
char buff2[] = {0};


char *num;
char *character;

void CompressStr(const char *SrcStr, char *DstStr)
{
	unsigned int count=0;
	int len = strlen(SrcStr);
	int i = 0;
	int j = 0;

	printf("len = %d\n", len);
	num = (char *)malloc(len+5);
	character = (char *)malloc(len+5);
	
	num[0] = 1;

	for(i=0; i<len; i++)
	{
		
		if(SrcStr[i] == SrcStr[i+1])
		{
			num[j]++;
			character[j] = SrcStr[i];
		}
		else
		{
			
			character[j] = SrcStr[i];
			j++;
			num[j] = 1;
		}
	}
	
	for(i=0; i<10; i++)
	{
		printf("%c ", character[i]);
	}
	printf("\n");
	for(i=0; i<10; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	
	j=0;
	for(i=0; i<len; i++)
	{
		DstStr[i] = character[j];

		if(num[j] == 1)
		{
			j++;
		}
		else
		{
			i++;
			DstStr[i] = num[j]+'0';
			j++;
		}

	}


	printf("DstStr = %s\n", DstStr);
}
int main(void)
{
	
	CompressStr(buff1, buff2);

	

	return 0;
}


