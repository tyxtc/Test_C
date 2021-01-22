#include <stdio.h>
#include <string.h>

void main()
{
	int temp = 50;
	int time = 5;

	int i = 0;

	FILE *fp;
	fp = fopen("fyf.txt", "wr");

	for(; temp<=230; temp+=5)
	{
		//fprintf(fp, "设置温度为%d度::设置温度为%d度:%x%x\n", temp, temp, 0xf3, temp);
		fprintf(fp, "温度为%d度::已将温度设置为%d度,请您设置工作时间:f0a3%x ::2>023 \n", temp, temp, temp);
		fprintf(fp, "设置为%d度::已将温度设置为%d度,请您设置工作时间:f0a3%x ::2>023 \n", temp, temp, temp);
		fprintf(fp, "%d度::已将温度设置为%d度,请您设置工作时间:f0a3%x ::2>023 \n", temp, temp, temp);

		fprintf(fp, "\n");
		//180度::已将温度设置为180度,您要烤多少分钟:f0a3b4::2>023
		
	}
	fprintf(fp, "\n\n");

	for(; time<=90; time+=5)
	{
		//fprintf(fp, "设置时间为%d分钟::设置时间为%d分钟:%x%+x\n", time, time, 0xf4, time);
		//30分钟::已将工作时间设置为30分钟,是否开始工作:f0a41e::3>034
		fprintf(fp, "工作%d分钟::已将工作时间设置为%d分钟,是否开始工作:f0a4%x ::3>034 \n", time, time, time);
		fprintf(fp, "工作时间为%d分钟::已将工作时间设置为%d分钟,是否开始工作:f0a4%x ::3>034 \n", time, time, time);
		fprintf(fp, "设置为%d分钟::已将工作时间设置为%d分钟,是否开始工作:f0a4%x ::3>034 \n", time, time, time);
		fprintf(fp, "%d分钟::已将工作时间设置为%d分钟,是否开始工作:f0a4%x ::3>034 \n", time, time, time);

		fprintf(fp, "\n");

	}
	fprintf(fp, "\n\n");

}

