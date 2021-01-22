#include <stdio.h>
#include <math.h>
#include <string.h>



int StrToHex(char * str)
{
	int i = 0;
	int num = 0;
	int sum = 0;
	while(str[i] != '\0')
	{
		switch(str[i])
		{
			case 'F':
			case 'f':
				num = 15;break;
			case 'E':
			case 'e':
				num = 14;break;
			case 'D':
			case 'd':
				num = 13;break;
			case 'C':
			case 'c':
				num = 12;break;
			case 'B':
			case 'b':
				num = 11;break;
			case 'A':
			case 'a':
				num = 10;break;	
				
			default:
				num = str[i]-'0';break;
		}
		sum = sum*16+num;
		i++;
	}
	return sum;		
}

void Calculator(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char a = 0;
	int resault = 0;
	char read_buf[500] = {0};
	char char_buf[50][5] = {0};
	int num_buf[50] = {0};


	printf("ÇëÊäÈëÊı¾İ£º\n");
	gets(read_buf);
    printf("%s\n", read_buf);
    j = strlen(read_buf);
    printf("j = %d\n", j);
    
    while(i<j)
    {
    	if(read_buf[i] != ' ')
    	{	
    		printf("%c ", read_buf[i]);
    		char_buf[k][a] = read_buf[i];
    		a++;  		
		}
		i++;

		if(read_buf[i] == ' ')
		{
			char_buf[k][a+1] = '\0';
			k++;
			a=0;
		}
	}
	char_buf[k][a+1] = '\0';
	k++;
	printf("\n");
	//printf("k = %d\n", k);

	
	for(i=0; i<k; i++)
    {
    	printf("%s ", (char *)char_buf[i]);
	}
	printf("\n");
	
	for(i=0; i<k; i++)
    {
    	num_buf[i] = StrToHex((char *)char_buf[i]);
    	printf("%x ", num_buf[i]);
		resault += num_buf[i];
	}
	printf("\n");

	resault &= 0x000000ff;
	printf("resault = %#x\n", resault);
	printf("\n");
	printf("\n");
	
}



void main(void)
{
	int i = 1;
	while(i>0)
	{
		i++;
		Calculator();
	}
}
