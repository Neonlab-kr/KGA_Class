#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Shape
{
public:
	virtual void Draw() const
	{
		cout << "�θ� Ŭ���� Shape" << endl;
	}
	virtual ~Shape() = default;
};


class Circle : public Shape
{
public:
	void Draw() const override
	{
		cout << "�ڽ� Ŭ���� Circle" << endl;
	}
	void CircleFunc()
	{
		cout << "Cirle Ŭ������ ����Լ�" << endl;
	}
};

class Rectangle : public Shape
{
public:
	void Draw() const override
	{
		cout << "�ڽ� Ŭ���� Rectangle" << endl;
	}
	void RectangleFunc()
	{
		cout << "Rectangle Ŭ������ ����Լ�" << endl;
	}
};

int main()
{
	Shape* shape1;
	Shape* shape2;
	shape1 = new Circle();
	shape2 = new Rectangle();

	shape1->Draw();
	shape2->Draw();

	Circle* c = dynamic_cast<Circle*>(shape1);//�ٿ�ĳ����

	c->CircleFunc();

	return 0;
}