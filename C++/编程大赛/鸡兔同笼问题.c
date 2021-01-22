#include <stdio.h>
#include <string.h>


int GetFowlsNum(int HeadNum, int FootNum, int *ChickenNum, int *RabbitNum)
{
	int chicknum = 0;
	int rabbitnum = 0;

	for(chicknum=0; chicknum<=HeadNum; chicknum++)
	{
		if(chicknum*2+(HeadNum-chicknum)*4 == FootNum)
		{
			*ChickenNum = chicknum;
			*RabbitNum = HeadNum-chicknum;
			return 0;
		}
	}

	printf("输入的数据有误!\n");
	*ChickenNum = 0;
	*RabbitNum = 0;
	return -1;
}


int main(void)
{
	int i = 0;
	int head_num = 0;
	int foot_num = 0;
	int ChickenNum;
	int RabbitNum;
	
	printf("请输入头的个数:");
	scanf("%d", &head_num);
	printf("请输入脚的个数:");
	scanf("%d", &foot_num);

	GetFowlsNum(head_num, foot_num, &ChickenNum, &RabbitNum);

	printf("ChickenNum = %d\n", ChickenNum);
	printf("RabbitNum = %d\n", RabbitNum);
}


