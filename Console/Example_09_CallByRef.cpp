#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Value(int n);//CallByValue
void Address(int* n);//CallByRef

void Reference(int& n);//������ ������ ���� ���� �����Ϳ� ���� �����ϵ��� ����. 
//�����ʹ� ��ȿ���� ���� �ּҸ� ������ �� ����! -> �߸��� �޸� ������ �߻� ����.

void Swap(int a,int b);
void SwapAddress(int* a,int* b);
void SwapRefernce(int& a,int& b);



int main()
{
	int num = 30;
	Value(num);
	cout << "num�� �� : " << num << endl;
	cout << "num�� �ּҰ� : " << &num << endl;

	cout << endl;

	int num1 = 30;
	Address(&num1);
	cout << "num1�� �� : " << num1 << endl;
	cout << "num1�� �ּҰ� : " << &num1 << endl;

	cout << endl;

	int num2 = 30;
	Reference(num2);
	cout << "num1�� �� : " << num2 << endl;
	cout << "num1�� �ּҰ� : " << &num2 << endl;

	cout << endl;

	int a = 1, b = 2;
	cout << "�ʱ� ������" << endl;
	cout << a << ' ' << b << endl;

	Swap(a, b);
	cout << "Swap() �� ������" << endl;
	cout << a << ' ' << b << endl;

	SwapAddress(&a, &b);
	cout << "SwapAddress() �� ������" << endl;
	cout << a << ' ' << b << endl;

	SwapRefernce(a, b);
	cout << "SwapReference() �� ������" << endl;
	cout << a << ' ' << b << endl;

	return 0;
}

void Value(int n)
{
	n = 10;
	cout << "n�� �� : " << n << endl;
	cout << "n�� �ּҰ� : " << &n << endl;
}

void Address(int* n)
{
	*n = 10;
	cout << "n�� �� : " << *n << endl;
	cout << "n�� �ּҰ� : " << &n << endl;
}

void Reference(int& n)
{
	n = 10;
	cout << "n�� �� : " << n << endl;
	cout << "n�� �ּҰ� : " << &n << endl;
}

void Swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void SwapAddress(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SwapRefernce(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
