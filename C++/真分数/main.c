
#include<stdio.h>
int main()
{
    int i, num1, num2, temp, n=0;  /*n��¼�������ĸ���*/
    printf("��ĸ��60���������:\n");
    for(i=1; i<60; i++)  /*���60���ڵ�ȫ������*/
    {
        num1 = 60;
        num2 = i;
        /*����շת�����������Լ��*/
        while(num2 != 0)
        {
            temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }
        if(num1 == 1)  /*�����Լ��Ϊ1����Ϊ��������*/
        {
            n++;
            printf("%2d/60\n", i);
            if(n%8 == 0)  /*ÿ�����8����*/
                printf("\n\n");
        }
    }
  
    return 0;
}
