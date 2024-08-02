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

	void PrintInfo() const // 멤버함수가 객체의 함수를 변경하지 않도록 하는 const
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
		//여기서 할 필요가 없음
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