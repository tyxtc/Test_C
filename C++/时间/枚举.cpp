#include <iostream>
using namespace std;

// ÿ��ö��Ԫ��������ʱ������һ������ֵ��Ĭ�ϴ� 0 ��ʼ������� 1��
//**************************************************************

int test1(void)
{
	enum days
	{
	    one,
	    two,
	    three
	} day;

	day = one;
	switch(day)
	{
	case one:
		cout << "one" << endl;
		break;
	case two:
		cout << "two" << endl;
		break;
	default:
		cout << "three" << endl;
		break;
	}
	return 0;
}

//**************************************************************
enum time 
{ 
    first,second,
    third,forth,fifth
};

int test2(void)
{
    enum time a=fifth;
    if (a==fifth) 
    {
        cout << "Succeed!" <<endl;
    }
    return 0;
}


//**************************************************************
int  test3(void)
{
    enum rank
    {
        first,second,third
    };

    int nRank=1;
    switch (nRank)
    {
        case first:
            cout << "��һ��";
            break;
        case second:
            cout << "�ڶ���";
            break;
        case third:
            cout << "������";
            break;
        default:
            break;
    }
    // system("pause");
    return 0;
}

//**************************************************************
int main(void)
{
	test1();
	test2();
	test3();
	
	return 0;
}
