#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//��������
extern int num1;
extern void Count();

int main()
{
	//cout << staticGlobalVariable;
	cout << num1 << endl;
	Count();
	Count();
	Count();
	Count();
}