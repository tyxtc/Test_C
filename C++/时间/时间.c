#include <stdio.h>
#include <time.h>

void main(void)
{
	time_t timer = time(NULL);
	
	printf("%s\n", __TIME__);
	printf("%s\n", __DATE__);
	
	timer = time(0);
	printf("ctime is %s\n", ctime(&timer));//�õ�����ʱ��
	
	timer = time(0);
	printf("ctime is %s\n", ctime(&timer));//�õ�����ʱ��
}
