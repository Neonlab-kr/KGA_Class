#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Player
{
public:
	string name;
	int mAtk;
	int mDef;
	//const int a;
	//int& b;

	Player()
	{
		name = "winter";
		mAtk = 10;
		mDef = 20;
	}

	Player(const string& playerName, int playerAtk, int playerDef)
	{
		name = playerName;
		mAtk = playerAtk;
		mDef = playerDef;
	}

	void PrintInfo() const // ����Լ��� ��ü�� �Լ��� �������� �ʵ��� �ϴ� const
	{
		cout << name << endl;
	}
};

class Moster
{
public:
	string name;
	int Atk;
	int Def;
	const int a;
	int* p;

	Moster(const string& monsterName, const int monsterAtk, const int monsterDef) : name(monsterName), Atk(monsterAtk), Def(monsterDef), a(1), p(nullptr)
	{
		//���⼭ �� �ʿ䰡 ����
	}
};


int main()
{
	Player* player = new Player();
	player->PrintInfo();

	delete player;
	player = nullptr;

	Player* player1 = new Player("testname",10,50);
	player1->PrintInfo();

	delete player1;
	player1 = nullptr;


	return 0;
}