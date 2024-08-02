#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class MyClass
{
public:
	MyClass(int size);//생성자
	~MyClass();//소멸자

private:
	int* data;
};

MyClass::MyClass(int size)
{
	data = new int[size];
	cout << "생성자 호출" << endl;
}

MyClass::~MyClass()
{
	delete[] data;
	data = nullptr;
	cout << "소멸자 호출" << endl;
}

int main()
{
	MyClass* m = new MyClass(10);
	delete m;
	return 0;
}