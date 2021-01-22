#include <iostream>
using namespace std;

// 每个枚举元素在声明时被分配一个整型值，默认从 0 开始，逐个加 1。
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
            cout << "第一名";
            break;
        case second:
            cout << "第二名";
            break;
        case third:
            cout << "第三名";
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
