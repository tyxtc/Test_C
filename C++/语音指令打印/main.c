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
		//fprintf(fp, "�����¶�Ϊ%d��::�����¶�Ϊ%d��:%x%x\n", temp, temp, 0xf3, temp);
		fprintf(fp, "�¶�Ϊ%d��::�ѽ��¶�����Ϊ%d��,�������ù���ʱ��:f0a3%x ::2>023 \n", temp, temp, temp);
		fprintf(fp, "����Ϊ%d��::�ѽ��¶�����Ϊ%d��,�������ù���ʱ��:f0a3%x ::2>023 \n", temp, temp, temp);
		fprintf(fp, "%d��::�ѽ��¶�����Ϊ%d��,�������ù���ʱ��:f0a3%x ::2>023 \n", temp, temp, temp);

		fprintf(fp, "\n");
		//180��::�ѽ��¶�����Ϊ180��,��Ҫ�����ٷ���:f0a3b4::2>023
		
	}
	fprintf(fp, "\n\n");

	for(; time<=90; time+=5)
	{
		//fprintf(fp, "����ʱ��Ϊ%d����::����ʱ��Ϊ%d����:%x%+x\n", time, time, 0xf4, time);
		//30����::�ѽ�����ʱ������Ϊ30����,�Ƿ�ʼ����:f0a41e::3>034
		fprintf(fp, "����%d����::�ѽ�����ʱ������Ϊ%d����,�Ƿ�ʼ����:f0a4%x ::3>034 \n", time, time, time);
		fprintf(fp, "����ʱ��Ϊ%d����::�ѽ�����ʱ������Ϊ%d����,�Ƿ�ʼ����:f0a4%x ::3>034 \n", time, time, time);
		fprintf(fp, "����Ϊ%d����::�ѽ�����ʱ������Ϊ%d����,�Ƿ�ʼ����:f0a4%x ::3>034 \n", time, time, time);
		fprintf(fp, "%d����::�ѽ�����ʱ������Ϊ%d����,�Ƿ�ʼ����:f0a4%x ::3>034 \n", time, time, time);

		fprintf(fp, "\n");

	}
	fprintf(fp, "\n\n");

}

