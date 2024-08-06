#include <iostream>

class CPrint
{
public:
	void Print(int a)
	{
		std::cout << "int�� ���" << a << std::endl;
	}
	void Print(double a)
	{
		std::cout << "double�� ���" << a << std::endl;
	}
};

class Parent
{
public:
	virtual ~Parent() = default;//�⺻ ������ �����Ϸ����� ��û
	virtual void Show()
	{
		std::cout << "�θ� Ŭ���� Show()" << std::endl;
	}
};

class Child :public Parent
{
public:
	void Show() override
	{
		std::cout << "�ڽ� Ŭ���� Show()" << std::endl;
	}
};

int main()
{
	//�������ε�(�ڷ����� ���� ȣ������ �̸� ������)
	CPrint c;
	c.Print(10);
	c.Print(20.5);

	//���� ���ε�(����Ű�� �ִ� ��ü�� Ÿ�Կ� ���� ��Ÿ�ӿ� ȣ�� ����� ������)
	Parent* pPtr = new Child();
	pPtr->Show();

	delete pPtr;

	return 0;
}