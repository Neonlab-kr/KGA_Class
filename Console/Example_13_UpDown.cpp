#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Shape
{
public:
	virtual void Draw() const
	{
		cout << "부모 클래스 Shape" << endl;
	}
	virtual ~Shape() = default;
};


class Circle : public Shape
{
public:
	void Draw() const override
	{
		cout << "자식 클래스 Circle" << endl;
	}
	void CircleFunc()
	{
		cout << "Cirle 클래스의 멤버함수" << endl;
	}
};

class Rectangle : public Shape
{
public:
	void Draw() const override
	{
		cout << "자식 클래스 Rectangle" << endl;
	}
	void RectangleFunc()
	{
		cout << "Rectangle 클래스의 멤버함수" << endl;
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

	Circle* c = dynamic_cast<Circle*>(shape1);//다운캐스팅

	c->CircleFunc();

	return 0;
}