#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

void Menu();//���˵�
void Introduce();//���˵��������

void BasicCal();//������
void CalPrint();//��������ӭ����
double ReadNum(char BackForm[], int *i);//�����ַ�ת���ɸ�����ʵ��
void PostFix(char CalForm[], char BackForm[]);//��׺���ʽת��Ϊ��׺���ʽ
double CalPost(char BackForm[]);//�����׺���ʽ��ֵ
int IsOperation(char Operation);//�ж��ַ��Ƿ�Ϊ������
int Priority(char Operation);//�ж��ַ������ȼ�
void TransForm(char Expression[], char CalForm[]);//��ʽת��

void DrawPic();//��ͼ

void main()
{
	Menu();
	system("pause");
}


//���˵���ť
void Menu()
{
	system("cls");//����

	printf("***************MathMuseum***************\n");
	printf("****************************************\n");
	printf("0.�������\n");
	printf("1.��������\n");
	printf("2.�򵥻�ͼ\n");
	printf("�������蹦��ǰ�ı�ţ�");

	while(1)
	{
		switch(_getch())
		{
		case 48:
			Introduce();
			break;//ѡ��0
		case 49:
			BasicCal();
			break;//ѡ��1
		case 50:
			DrawPic();
			break;//ѡ��2
		default:
			printf("\n�����������ţ�");
			break; //����������
		}
	}


}

//���˵��������
void Introduce()
{
	system("cls");
	printf("��ӭ����MathMuseum��\n");
	printf("MathMuseum��һ���򵥵����ڽ���ѧ���������C���ԵĻ�����ʵ�ֵ�С����\n");
	printf("����ESC�����ز˵���\n");

	while(1) //ESC�ļ���Ϊ27
	{
		if(_getch()==27)
			Menu();
		else
			printf("���������룡\n");
//break;
	}
}


//��������ӭ����
void BasicCal()
{
	char Expression[100];//���ʽ
	char CalForm[100];//����ʽ
	char BackForm[100];//��׺����ʽ
	int DotNum;//С�����λ��
	int Sign;
	int Flag;

	CalPrint();//��������ӭ����
	do
	{
		printf("������ʽ:");

		scanf_s("%s",Expression);
		TransForm(Expression, CalForm);
		PostFix(CalForm, BackForm);

		printf("���������λС����");
		scanf_s("%d",&DotNum);

		printf("%.*lf\n",DotNum, CalPost(BackForm));

		while(1)
		{
			Flag=3;
			printf("�������㣿1/0");
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
				printf("�Ƿ����룬���������룡\n");
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
	printf("||        ��ӭʹ�ö๦�ܼ�����         | |       \n");
	printf("||_____________________________________| |   \n");
	printf("||                    ͼ�������ο�     | |     \n");
	printf("||_____________________________________| |   \n");
	printf("|                                        |   \n");
	printf("|___  ___  ___  ___  ___  ___  ___  ___  |   \n");
	printf("|________  ________  ________  ________  |   \n");
	printf("||  ��  |  |  ��  |  |  ��  |  |  ��  |  |     \n");
	printf("||______|  |______|  |______|  |______|  |   \n");
	printf("|________  ________  ________  ________  |   \n");
	printf("||  ��  |  |  ��  |  |  ��  |  |  ��  |  |     \n");
	printf("||______|  |______|  |______|  |______|  |   \n");
	printf("| _______  ________  ________  ________  |   \n");
	printf("||  ��  |  |  ��  |  |  ��  |  |  ��  |  |     \n");
	printf("||______|  |______|  |______|  |______|  |   \n");
	printf("|________  ________  ________  ________  |   \n");
	printf("||  ��  |  |  ��  |  |  AC  |  |  ��  |  |     \n");
	printf("||______|  |______|  |______|  |______|  |   \n");
	printf("��������֧��+��-��*��/���������㡣\n");
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
		return 1;//+,-������1
	case '*':
	case '/':
		return 2;//*,/������2
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
		return 1;//ƽ�����������Ӽ��˳���Ϊ�����ַ�
	default:
		return 0;
	}
}

void DrawPic()
{
}
