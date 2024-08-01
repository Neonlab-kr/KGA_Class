#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Value(int n);//CallByValue
void Address(int* n);//CallByRef

void Reference(int& n);//변수의 별명을 만들어서 원본 데이터에 직접 접근하도록 해줌. 
//포인터는 유효하지 않은 주소를 참조할 수 있음! -> 잘못된 메모리 접근이 발생 가능.

void Swap(int a,int b);
void SwapAddress(int* a,int* b);
void SwapRefernce(int& a,int& b);



int main()
{
	int num = 30;
	Value(num);
	cout << "num의 값 : " << num << endl;
	cout << "num의 주소값 : " << &num << endl;

	cout << endl;

	int num1 = 30;
	Address(&num1);
	cout << "num1의 값 : " << num1 << endl;
	cout << "num1의 주소값 : " << &num1 << endl;

	cout << endl;

	int num2 = 30;
	Reference(num2);
	cout << "num1의 값 : " << num2 << endl;
	cout << "num1의 주소값 : " << &num2 << endl;

	cout << endl;

	int a = 1, b = 2;
	cout << "초기 데이터" << endl;
	cout << a << ' ' << b << endl;

	Swap(a, b);
	cout << "Swap() 후 데이터" << endl;
	cout << a << ' ' << b << endl;

	SwapAddress(&a, &b);
	cout << "SwapAddress() 후 데이터" << endl;
	cout << a << ' ' << b << endl;

	SwapRefernce(a, b);
	cout << "SwapReference() 후 데이터" << endl;
	cout << a << ' ' << b << endl;

	return 0;
}

void Value(int n)
{
	n = 10;
	cout << "n의 값 : " << n << endl;
	cout << "n의 주소값 : " << &n << endl;
}

void Address(int* n)
{
	*n = 10;
	cout << "n의 값 : " << *n << endl;
	cout << "n의 주소값 : " << &n << endl;
}

void Reference(int& n)
{
	n = 10;
	cout << "n의 값 : " << n << endl;
	cout << "n의 주소값 : " << &n << endl;
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
