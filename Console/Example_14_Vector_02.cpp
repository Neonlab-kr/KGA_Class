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
		cout << "�̸� : " << name << ", ���ݷ� : " << damage << endl;
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

	cout << "vec�� capacity : " << vec.capacity() << endl;//6

	vec.clear();

	cout << "vec�� capacity after clear : " << vec.capacity() << endl;//6

	vector<int>().swap(vec);

	cout << "vec�� capacity after swap : " << vec.capacity() << endl;//0

	system("cls");

	vector<int> myVec = {1,2,3,4,5,6};
	ShowPrintValue(myVec);

	system("cls");

	vector<Weapon> weapon;

	weapon.push_back(Weapon("���", 50));
	weapon.push_back(Weapon("Ȱ", 10));
	weapon.push_back(Weapon("�ܰ�", 100));
	weapon.push_back(Weapon("�����", 600));

	for (const Weapon& w : weapon)
	{
		w.Print();
	}

	vector<Weapon*> weapon1;
	weapon1.push_back(new Weapon("���", 50));
	weapon1.push_back(new Weapon("Ȱ", 10));
	weapon1.push_back(new Weapon("�ܰ�", 100));
	weapon1.push_back(new Weapon("�����", 600));

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