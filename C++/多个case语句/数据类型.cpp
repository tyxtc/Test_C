#include<iostream>  
#include<string>  
#include <limits>  
using namespace std;  
  
void fun1(int test)  
{  
	cout << "test = " << test <<endl;
	switch(test)
	{
		case 0:cout << 0 <<endl;break;
		case 1:cout << 1 <<endl;
		case 2:cout << 2 <<endl;
		case 3:cout << 3 <<endl;
		case 4:cout << 4 <<endl;
		
	} 
}

int main(void)
{
	int i = 0;
	for(i=0; i<=4; i++)
	{
		fun1(i);
	}
	return 0;
}
