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
		name = "기본";
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

	cout << "구조체 p.x의 값 : " << p.x << endl;
	cout << "구조체 p.x의 값 : " << p.y << endl;
	p.Print();

	Point p1 = { 50,120 }; //생성과 동시에 초기화

	Monster monster;
	Monster dragon = Monster("드래곤", 250, 100);
	Monster slime = Monster("슬라임", 10, 3);

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
	cout << "포인트 구조체 멤버 함수임" << endl;
}
