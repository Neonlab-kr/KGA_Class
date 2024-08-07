#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class Shape
{
public:
	virtual void draw() const = 0;
	virtual T area() const = 0;
};

template <typename T>/
class Circle : public Shape<T>
{
private:
	const T radius;

public:
	Circle() : radius(1) {};
	Circle(T r) : radius(r) {};
	void draw() const override
	{
		cout << "원의 반지름 : " << radius << endl;
	}

	T area() const override
	{
		return radius * radius * 3.14;
	}
};

template <typename T>
class Rectangle : public Shape<T>
{
private:
	const T width;
	const T height;

public:
	Rectangle() : width(1), height(1){};
	Rectangle(T w, T h) : width(w), height(h) {};
	void draw() const override
	{
		cout << "사각형의 가로 : " << width << ", 사각형의 세로 : " << height << endl;
	}

	T area() const override
	{
		return width * height;
	}
};

template <typename T>
void Show(const Shape<T>* shapePtr)
{
	shapePtr->draw();
	shapePtr->area();
}

int main()
{
	Circle<double> circle(3.14);
	Rectangle<int> rect(5, 5);

	circle.draw();
	circle.area();

	rect.draw();
	rect.area();

	Show(&circle);

	Shape<double>* ptr = &circle;
	Show(ptr);

	return 0;
}