#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

void Menu();//主菜单
void Introduce();//主菜单程序介绍

void BasicCal();//计算器
void CalPrint();//计算器欢迎界面
double ReadNum(char BackForm[], int *i);//数字字符转换成浮点型实数
void PostFix(char CalForm[], char BackForm[]);//中缀表达式转换为后缀表达式
double CalPost(char BackForm[]);//计算后缀表达式的值
int IsOperation(char Operation);//判断字符是否为操作符
int Priority(char Operation);//判断字符的优先级
void TransForm(char Expression[], char CalForm[]);//格式转化

void DrawPic();//画图

void main()
{
	Menu();
	system("pause");
}


//主菜单按钮
void Menu()
{
	system("cls");//清屏

	printf("***************MathMuseum***************\n");
	printf("****************************************\n");
	printf("0.程序介绍\n");
	printf("1.基本运算\n");
	printf("2.简单画图\n");
	printf("输入所需功能前的编号：");

	while(1)
	{
		switch(_getch())
		{
		case 48:
			Introduce();
			break;//选择0
		case 49:
			BasicCal();
			break;//选择1
		case 50:
			DrawPic();
			break;//选择2
		default:
			printf("\n请重新输入编号：");
			break; //按其他按键
		}
	}


}

//主菜单程序介绍
void Introduce()
{
	system("cls");
	printf("欢迎来到MathMuseum！\n");
	printf("MathMuseum是一个简单的用于将数学计算概念在C语言的环境下实现的小程序。\n");
	printf("按“ESC”返回菜单键\n");

	while(1) //ESC的键码为27
	{
		if(_getch()==27)
			Menu();
		else
			printf("请重新输入！\n");
//break;
	}
}


//计算器欢迎界面
void BasicCal()
{
	char Expression[100];//表达式
	char CalForm[100];//计算式
	char BackForm[100];//后缀计算式
	int DotNum;//小数点后位数
	int Sign;
	int Flag;

	CalPrint();//计算器欢迎界面
	do
	{
		printf("输入表达式:");

		scanf_s("%s",Expression);
		TransForm(Expression, CalForm);
		PostFix(CalForm, BackForm);

		printf("输出保留几位小数：");
		scanf_s("%d",&DotNum);

		printf("%.*lf\n",DotNum, CalPost(BackForm));

		while(1)
		{
			Flag=3;
			printf("继续计算？1/0");
			Sign=_getch();
			printf("%c\n",Sign);
			switch(Sign)
			{
			case '1':
				Flag=1;
				_getch();
				break;
			case '0':
				Flag=0;
				_getch();
				break;
			default:
				printf("非法输入，请重新输入！\n");
			}
			if(Flag==1||Flag==0)
				break;
		}
	}
	while(Flag==1);
	system("pause");
}


void CalPrint()
{
	system("cls");

	printf("|_______________________________________ |   \n");
	printf("||                                     | |   \n");
	printf("||        欢迎使用多功能计算器         | |       \n");
	printf("||_____________________________________| |   \n");
	printf("||                    图案仅供参考     | |     \n");
	printf("||_____________________________________| |   \n");
	printf("|                                        |   \n");
	printf("|___  ___  ___  ___  ___  ___  ___  ___  |   \n");
	printf("|________  ________  ________  ________  |   \n");
	printf("||  ⑨  |  |  ⑧  |  |  ⑦  |  |  ×  |  |     \n");
	printf("||______|  |______|  |______|  |______|  |   \n");
	printf("|________  ________  ________  ________  |   \n");
	printf("||  ⑥  |  |  ⑤  |  |  ④  |  |  －  |  |     \n");
	printf("||______|  |______|  |______|  |______|  |   \n");
	printf("| _______  ________  ________  ________  |   \n");
	printf("||  ③  |  |  ②  |  |  ①  |  |  ＋  |  |     \n");
	printf("||______|  |______|  |______|  |______|  |   \n");
	printf("|________  ________  ________  ________  |   \n");
	printf("||  〇  |  |  ＝  |  |  AC  |  |  ÷  |  |     \n");
	printf("||______|  |______|  |______|  |______|  |   \n");
	printf("本计算器支持+，-，*，/，（）运算。\n");
}


void TransForm(char Expression[], char CalForm[])
{
	int k,i,j=0;

	for (i=0; Expression[i]!='='; i++)
	{
		k=i+1;
		if(Expression[i]=='('&&Expression[k]=='-')
		{
			CalForm[j++]=Expression[i];
			CalForm[j++]='0';
		}
		else CalForm[j++]=Expression[i];
	}
	CalForm[j]='=';
}


void PostFix(char CalForm[], char BackForm[])
{
	int i=0,j=0,k=0;
	char opst[100];
	int top=0;
	opst[0]='=';
	top++;

	while(CalForm[i]!='=')
	{
		if((CalForm[i]>='0'&&CalForm[i]<='9')||CalForm[i]=='.')
			BackForm[j++]=CalForm[i];
		else if(CalForm[i]=='(')
		{
			opst[top]=CalForm[i];
			top++;
		}
		else if(CalForm[i]==')')
		{
			k=top-1;
			while(opst[k]!='(')
			{
				BackForm[j++]=opst[--top];
				k=top-1;
			}
			top--;
		}
		else if(IsOperation(CalForm[i]))
		{
			BackForm[j++]=' ';
			while(Priority(opst[top-1])>=Priority(CalForm[i]))
				BackForm[j++]=opst[--top];
			opst[top]=CalForm[i];
			top++;
		}
		i++;
	}

	while(top)
		BackForm[j++]=opst[--top];
	BackForm[j]='\0';
}


double CalPost(char BackForm[])
{
	double obst[10];
	int top=0;
	int i=0;
	double x1,x2;

	while(BackForm[i]!='=')
	{
		if(BackForm[i]>='0'&&BackForm[i]<='9')
		{
			obst[top]=ReadNum(BackForm,&i);
			top++;
		}
		else if(BackForm[i]==' ')
			i++;
		else if(BackForm[i]=='+')
		{
			x1=obst[--top];
			x2=obst[--top];
			obst[top]=x2-x1;
			i++;
			top++;
		}
		else if(BackForm[i]=='-')
		{
			x1=obst[--top];
			x2=obst[--top];
			obst[top]=x2-x1;
			i++;
			top++;
		}
		else if(BackForm[i]=='*')
		{
			x1=obst[--top];
			x2=obst[--top];
			obst[top]=x1*x2;
			i++;
			top++;
		}
		else if(BackForm[i]=='/')
		{
			x1=obst[--top];
			x2=obst[--top];
			obst[top]=x2/x1;
			i++;
			top++;
		}
	}
	return obst[0];
}


int Priority(char Operation)
{
	switch(Operation)
	{
	case '=':
		return -1;
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;//+,-都返回1
	case '*':
	case '/':
		return 2;//*,/都返回2
	default:
		return -1;
	}
}

double ReadNum(char BackForm[], int *i)
{
	double x=0.0;
	int k=0;

	while(BackForm[*i]>='0'&&BackForm[*i]<='9')
	{
		x=x*10+(BackForm[*i]-'0');
		(*i)++;
	}
	if(BackForm[*i]=='.')
	{
		(*i)++;
		while(BackForm[*i]>='0'&&BackForm[*i]<='9')
		{
			x=x*10+(BackForm[*i]-'0');
			(*i)++;
			k++;
		}
	}

	while(k-->0)
		x=x/10.0;
	return (x);
}


int IsOperation(char Operation)
{
	switch(Operation)
	{
	case '^':
	case 'K':
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;//平方，开方，加减乘除均为操作字符
	default:
		return 0;
	}
}

void DrawPic()
{
}
