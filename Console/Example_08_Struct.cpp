#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Student
{
	string name;
	int math;
	int english;
	int science;

	float Average()
	{
		return(math + english + science) / 3.0f;
	}
};

struct Point
{
	int x;
	int y;
	void Print();
};

struct Monster
{
	string name;
	int hp;
	int mp;

	Monster()
	{
		name = "�⺻";
		hp = 100;
		mp = 100;
	}

	Monster(string _name, int _hp, int _mp)
	{
		name = _name;
		hp = _hp;
		mp = _mp;
	}
};

void main()
{
	Point p;

	p.x = 10;
	p.y = 20;

	cout << "����ü p.x�� �� : " << p.x << endl;
	cout << "����ü p.x�� �� : " << p.y << endl;
	p.Print();

	Point p1 = { 50,120 }; //������ ���ÿ� �ʱ�ȭ

	Monster monster;
	Monster dragon = Monster("�巡��", 250, 100);
	Monster slime = Monster("������", 10, 3);

	cout << monster.name << endl;
	cout << monster.hp << endl;
	cout << monster.mp << endl;

	cout << "=====================================" << endl;

	cout << dragon.name << endl;
	cout << dragon.hp << endl;
	cout << dragon.mp << endl;
	cout << "=====================================" << endl;

	cout << slime.name << endl;
	cout << slime.hp << endl;
	cout << slime.mp << endl;
}

void Point::Print()
{
	cout << "����Ʈ ����ü ��� �Լ���" << endl;
}
