#include <iostream>
#include <string>
#include <limits>

using namespace std;

typedef struct 
{
	int num1;
	int num2;
	int num3;
}NUM;

NUM fyf;

/*
	//必须在函数体内部赋值 
	fyf.num1 = 0;
	fyf.num2 = 1;
	fyf.num3 = 2;
*/
const int a = 10; 
int main()
{
	fyf.num1 = 077;//8进制数 
	fyf.num2 = 1;
	fyf.num3 = 2;
	
	cout << fyf.num1 << endl;
	cout << fyf.num2 << endl;
	cout << fyf.num3 << endl;

	return 0;
}
