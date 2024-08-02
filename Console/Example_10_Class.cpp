#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Circle
{
	int radius;
	string color;

	double calArea()
	{
		return 3.14 * radius * radius;
	}
};

class Circle1
{
	int radius;
	std::string color;

	double calArea()
	{
		return 3.14 * radius * radius;
	}
};

class Student
{
public:

	void Print() { cout << "Student class's Print()" << endl; }
	void Print(int a, int b) { cout << "Student class's Print() overloading" << endl; }
	void Print(string str = "default parameter") { cout << str << endl; }

	int Sum(int a, int b);

private:

};

class Rectangle
{
private:
	int x, y;

public:
	Rectangle()
	{
		x = 1;
		y = 1;
	}

	Rectangle(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void printArea()
	{
		cout << "���� : " << x * y << endl;
	}
};

int main()
{
	Circle c;
	c.radius = 5;

	Circle1 cc;
	//cc.radius = 5;

	Rectangle r(5,5);
	r.printArea();

	Rectangle r1;
	r1.printArea();

	return 0;
}

int Student::Sum(int a, int b)
{
	return a + b;
}


/*
�ǽ� 1. �簢���� Ŭ������ ����� ������
��±��� �غ�����
*/