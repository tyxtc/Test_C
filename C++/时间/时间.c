#include <stdio.h>
#include <time.h>

void main(void)
{
	time_t timer = time(NULL);
	
	printf("%s\n", __TIME__);
	printf("%s\n", __DATE__);
	
	timer = time(0);
	printf("ctime is %s\n", ctime(&timer));//得到日历时间
	
	timer = time(0);
	printf("ctime is %s\n", ctime(&timer));//得到日历时间
}
