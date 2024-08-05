#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Parent
{
public :
	int publicValue;
	Parent() :publicValue(1), protectedValue(2), privateValue(3) {};
	
	void ShowValues()
	{
		cout << "�θ�Ŭ���� public�� : " << publicValue << endl;
		cout << "�θ�Ŭ���� protected�� : " << protectedValue << endl;
		cout << "�θ�Ŭ���� private�� : " << privateValue << endl;
	}

protected:
	int protectedValue;

private:
	int privateValue;

};

class ChildPublic : public Parent
{
public:
	void ShowValues()
	{
		cout << "�ڽ�Ŭ���� public�� : " << publicValue << endl;
		cout << "�ڽ�Ŭ���� protected�� : " << protectedValue << endl;
		//�ڽ� Ŭ�������� ���� �Ұ���
		//cout << "�ڽ�Ŭ���� private�� : " << privateValue << endl;
	}
};

class ChildProtected : protected Parent
{
public:
	void ShowValues()
	{
		cout << "�ڽ�Ŭ���� public�� : " << publicValue << endl;
		cout << "�ڽ�Ŭ���� protected�� : " << protectedValue << endl;
		//�ڽ� Ŭ�������� ���� �Ұ���
		//cout << "�ڽ�Ŭ���� private�� : " << privateValue << endl;
	}
};

class ChildPrivate : private Parent
{
public:
	void ShowValues()
	{
		cout << "�ڽ�Ŭ���� public�� : " << publicValue << endl;
		cout << "�ڽ�Ŭ���� protected�� : " << protectedValue << endl;
		//�ڽ� Ŭ�������� ���� �Ұ���
		//cout << "�ڽ�Ŭ���� private�� : " << privateValue << endl;
	}
};

#pragma region ��� ��� ����
class Character// ��� ĳ���͵��� ����� �Ӽ��� ����� ������ �θ� Ŭ����
{
public:
	string name;
	int Hp;

	Character(const string& n, const int h) : name(n), Hp(h) {}

	void TakeDamage(const int damage)
	{
		Hp -= damage;
		cout << name << "��(��)" << damage << "��ŭ ���ظ� �Ծ��� ü�� : " << Hp << endl;
	}
};

class Warrior :public Character// ���� ĳ���͸��� ����� ���⼭ ����
{
public:
	Warrior(const string& n, const int h) : Character(n,h){}// �ڽ� �����ڿ��� �θ� �����ڸ� ȣ��(�������� ȣ�� ������ �θ�-> �ڽ� ���̱� ������ ��� ����)

	void Attack()
	{
		cout << name << "��(��) Į�� �ֵθ��ϴ�." << endl;
	}
};

class Mage : public Character// ���� ĳ���͸��� ����� ���⼭ ����
{
public:
	Mage(const string& n, const int h) : Character(n, h) {}

	void CastSkill()
	{
		cout << name << "��(��) ��ų�� ����մϴ�." << endl;
	}
};

#pragma endregion

#pragma region Is-a/Has-a ����
class Weapon{};

class Sword :public Weapon//Is-a ����
{
public:
	void use()
	{
		cout << "���� ����մϴ�." << endl;
	}
};

class SwordMan
{
	Sword* sword;//Has-a ����
public:
	void attack()
	{
		sword->use();
	}
};

#pragma endregion


int main()
{
	ChildPublic c1;
	c1.ShowValues();
	cout << c1.publicValue << endl;

	//�θ� Ŭ������ private�� ��ӹ��� Ŭ���� ���ο����� ������ ����
	//cout << c1.protectedValue << endl;

	ChildProtected c2;
	c2.ShowValues();

	//protected ����̱� ������ �θ��� public ����� �θ��� protected�� �޾ƿ�
	//cout << c2.publicValue << endl;

	ChildPrivate c3;
	c3.ShowValues();

	//private ����̱� ������ �θ��� public�� protected ����� �θ��� private�� ����Ͽ� �޾ƿ�
	//cout << c3.publicValue << endl;



	Warrior* w = new Warrior("����", 100);
	w->Attack();// �ڽ�Ŭ������ ����Լ�
	w->TakeDamage(10);// �θ�Ŭ������ ����Լ�
}