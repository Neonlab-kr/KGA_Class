#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//��������
int num1 = 3;
int num2 = 4;

//���� ���� ���� -> ���� ���Ͽ����� ����
static int staticGlobalVariable = 100;

class Character
{
private:
	static int count;
	int num;

public:
	Character()
	{
		num = 0;
		count++;
	}
	static void PrintCount()
	{
		cout << count << endl;
		//cout << num << endl;
	}
};

int Character::count = 0;

void Count();

//int main()
//{
//	Count();
//	Count();
//}

void Count()
{
	static int x = 0;
	int y = 0;

	x++;
	y++;

	cout << x << ' ' << y << endl;
}
