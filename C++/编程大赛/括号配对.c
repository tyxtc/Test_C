#include <stdio.h>
#include <string.h>

unsigned char buff[20] = {0x00};
const unsigned char dp1[] = {0x05, 0x01, 0x02, 0x03, 0x04};
const unsigned char dp2[] = {0xff, 0x02, 0x02, 0x02, 0x02};


int main(void)
{

	int i = 0;
	int j = 0;
	int k = 0;
	
	char s1[50];	//��Ҫchar*p��Ȼ��gets(p)�����Ǵ���ģ���Ϊpû��ָ����Ч���ڴ棬������ָ���κηǷ���ַ
	char s1_left_flag = 0;
	char s1_right_flag = 0;
	int len = 0;
	int num = 0;
	char flag = 0;
	char s2[50] = {0};
	
	gets(s1);
	len = strlen(s1);

	printf("%d\n", len);
	for(i=0; i<len; i++)
	{
		if(s1[i] == ')' && flag == 0)
		{
			printf("�Ƿ����룬�˳�����\n");
			return -1;
		}

		if(s1[i] == '(')
		{
			num++;
			if(flag == 0)
			{
				flag = 1;
				//s1_left_flag = i;
			}
		}
		else if(s1[i] == ')')
		{
			num--;
		}
		s2[i] = num;
	}

	for(i=0; i<len; i++)
	{
		if(s2[i] != 0)
		{
			s1_left_flag = i;
			break;
		}
	}

	
	for(i=len; i>0; i--)
	{
		if(s2[i] != 0)
		{
			s1_right_flag = i+1;
			break;
		}
	}


	for(i=s1_left_flag; i<=s1_right_flag; i++)
	{
		putchar(s1[i]);
	}
	printf("\n");

	//printf("%s\n", s1);

	

}



//123+(123*234+456)+(123*3+4*5+8)*456-234