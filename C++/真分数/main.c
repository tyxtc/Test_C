
#include<stdio.h>
int main()
{
    int i, num1, num2, temp, n=0;  /*n记录最简分数的个数*/
    printf("分母是60的真分数有:\n");
    for(i=1; i<60; i++)  /*穷举60以内的全部分子*/
    {
        num1 = 60;
        num2 = i;
        /*采用辗转相除法求出最大公约数*/
        while(num2 != 0)
        {
            temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }
        if(num1 == 1)  /*若最大公约数为1，则为最简真分数*/
        {
            n++;
            printf("%2d/60\n", i);
            if(n%8 == 0)  /*每行输出8个数*/
                printf("\n\n");
        }
    }
  
    return 0;
}
