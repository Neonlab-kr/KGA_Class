#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int* p;//������ ���� p����

	int a = 2;
	p = &a;

	cout << "p�� ��(���� a�� �ּҰ�) : " << p << endl;
	cout << a << endl;
	cout << "*p�� ��(a�� ��) : " << *p << endl;
	*p = 100;
	cout << "���� �� *p�� ��(a�� ��) : " << *p << endl;


	//�����Ϳ� const
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
	//voidŸ�� ������
	void* vp;
	int c = 3;
	double d = 3.1;

	vp = &c;
	//*vp = 1;
	//(�ڷ���*)�� �������ν� �����ϰ� ��.
	cout << *(int*)vp << endl;

	return 0;
}