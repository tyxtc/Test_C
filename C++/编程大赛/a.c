#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 6


char character_lib[][N] = { 'a','a','a','a','a','a',\
							'b','b','b','b','b','b',\
							'c','c','c','c','c','c',\
							'd','d','d','d','d','d',\
							'e','e','e','e','e','e',\
							'f','f','f','f','f','f',};




typedef struct
{
	char x;
	char y;
}TYPE_ZB;


typedef struct
{
	TYPE_ZB x_y[100];
}TYPE_DOT;

TYPE_DOT character[15];

const char dest_arr[] = "abccdefffff";

int FindStat(char (*Map)[N], unsigned int iArrN, const char *PathStr)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	int m = 0;
	int n = 0;

	while(PathStr[k] != '\0')
	{
		for(i=0; i<iArrN; i++)//yÖá
		{
			for(j=0; j<iArrN; j++)//xÖá
			{
				if(PathStr[k] == Map[i][j])
				{					
					character[k].x_y[m].x = j;
					character[k].x_y[m].y = i;
					m++;
				}
			}
		}
		k++;
		m = 0;
	}
	
	
	for(i=0; i<k; i++)//yÖá
	{
		for(j=0; j<10; j++)//xÖá
		{
			printf("(%d,%d)", character[i].x_y[j].y, character[i].x_y[j].x);			
		}
		printf("\n");
	}
}
int main(void)
{
	
	FindStat(character_lib, N, dest_arr);
	
	return 0;
}


