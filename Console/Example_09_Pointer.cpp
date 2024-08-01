#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int* p;//포인터 변수 p선언

	int a = 2;
	p = &a;

	cout << "p의 값(변수 a의 주소값) : " << p << endl;
	cout << a << endl;
	cout << "*p의 값(a의 값) : " << *p << endl;
	*p = 100;
	cout << "변경 후 *p의 값(a의 값) : " << *p << endl;


	//포인터와 const
	int num = 0;
	int b;

	const int* pa = &num;
	//*pa = 100;
	pa = &b;

	int* const pb = &num;
	*pb = 100;
	//pb = &b;

	const int* const pc = &num;
	//*pc = 100;
	//pc = &b;


	cout << "==================================" << endl;
	//void타입 포인터
	void* vp;
	int c = 3;
	double d = 3.1;

	vp = &c;
	//*vp = 1;
	//(자료형*)를 붙임으로써 가능하게 함.
	cout << *(int*)vp << endl;

	return 0;
}