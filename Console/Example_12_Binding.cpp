#include <iostream>

class CPrint
{
public:
	void Print(int a)
	{
		std::cout << "int형 출력" << a << std::endl;
	}
	void Print(double a)
	{
		std::cout << "double형 출력" << a << std::endl;
	}
};

class Parent
{
public:
	virtual ~Parent() = default;//기본 구현을 컴파일러에게 요청
	virtual void Show()
	{
		std::cout << "부모 클래스 Show()" << std::endl;
	}
};

class Child :public Parent
{
public:
	void Show() override
	{
		std::cout << "자식 클래스 Show()" << std::endl;
	}
};

int main()
{
	//정적바인딩(자료형에 의해 호출대상이 미리 결정됨)
	CPrint c;
	c.Print(10);
	c.Print(20.5);

	//동적 바인딩(가리키고 있는 객체의 타입에 따라 런타임에 호출 대상이 결정됨)
	Parent* pPtr = new Child();
	pPtr->Show();

	delete pPtr;

	return 0;
}