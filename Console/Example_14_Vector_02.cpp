#include <iostream>
#include <vector>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Weapon
{
private:
	string name;
	int damage;

public:
	Weapon(const string& name, int damage) : name(name), damage(damage) {}
	void Print() const
	{
		cout << "이름 : " << name << ", 공격력 : " << damage << endl;
	}

};

template <typename T>
void ShowPrintValue(const vector<T>& vec)
{
	for (T i : vec) cout << i << endl;
}

int main()
{
	vector<int> vec(6, 1);

	cout << "vec의 capacity : " << vec.capacity() << endl;//6

	vec.clear();

	cout << "vec의 capacity after clear : " << vec.capacity() << endl;//6

	vector<int>().swap(vec);

	cout << "vec의 capacity after swap : " << vec.capacity() << endl;//0

	system("cls");

	vector<int> myVec = {1,2,3,4,5,6};
	ShowPrintValue(myVec);

	system("cls");

	vector<Weapon> weapon;

	weapon.push_back(Weapon("장검", 50));
	weapon.push_back(Weapon("활", 10));
	weapon.push_back(Weapon("단검", 100));
	weapon.push_back(Weapon("집행검", 600));

	for (const Weapon& w : weapon)
	{
		w.Print();
	}

	vector<Weapon*> weapon1;
	weapon1.push_back(new Weapon("장검", 50));
	weapon1.push_back(new Weapon("활", 10));
	weapon1.push_back(new Weapon("단검", 100));
	weapon1.push_back(new Weapon("집행검", 600));

	for (const Weapon*& w : weapon1)
	{
		w->Print();
	}

	for (const Weapon*& w : weapon1)
	{
		delete w;
	}

	return 0;
}