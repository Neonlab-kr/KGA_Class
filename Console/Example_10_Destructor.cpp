#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class MyClass
{
public:
	MyClass(int size);//������
	~MyClass();//�Ҹ���

private:
	int* data;
};

MyClass::MyClass(int size)
{
	data = new int[size];
	cout << "������ ȣ��" << endl;
}

MyClass::~MyClass()
{
	delete[] data;
	data = nullptr;
	cout << "�Ҹ��� ȣ��" << endl;
}

int main()
{
	MyClass* m = new MyClass(10);
	delete m;
	return 0;
}