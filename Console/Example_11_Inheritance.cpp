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
		cout << "부모클래스 public값 : " << publicValue << endl;
		cout << "부모클래스 protected값 : " << protectedValue << endl;
		cout << "부모클래스 private값 : " << privateValue << endl;
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
		cout << "자식클래스 public값 : " << publicValue << endl;
		cout << "자식클래스 protected값 : " << protectedValue << endl;
		//자식 클래스에서 접근 불가능
		//cout << "자식클래스 private값 : " << privateValue << endl;
	}
};

class ChildProtected : protected Parent
{
public:
	void ShowValues()
	{
		cout << "자식클래스 public값 : " << publicValue << endl;
		cout << "자식클래스 protected값 : " << protectedValue << endl;
		//자식 클래스에서 접근 불가능
		//cout << "자식클래스 private값 : " << privateValue << endl;
	}
};

class ChildPrivate : private Parent
{
public:
	void ShowValues()
	{
		cout << "자식클래스 public값 : " << publicValue << endl;
		cout << "자식클래스 protected값 : " << protectedValue << endl;
		//자식 클래스에서 접근 불가능
		//cout << "자식클래스 private값 : " << privateValue << endl;
	}
};

#pragma region 상속 사용 예시
class Character// 모든 캐릭터들의 공통된 속성과 기능을 가지는 부모 클래스
{
public:
	string name;
	int Hp;

	Character(const string& n, const int h) : name(n), Hp(h) {}

	void TakeDamage(const int damage)
	{
		Hp -= damage;
		cout << name << "이(가)" << damage << "만큼 피해를 입었음 체력 : " << Hp << endl;
	}
};

class Warrior :public Character// 개별 캐릭터만의 기능은 여기서 구현
{
public:
	Warrior(const string& n, const int h) : Character(n,h){}// 자식 생성자에서 부모 생성자를 호출(생성자의 호출 순서는 부모-> 자식 순이기 때문에 사용 가능)

	void Attack()
	{
		cout << name << "이(가) 칼을 휘두릅니다." << endl;
	}
};

class Mage : public Character// 개별 캐릭터만의 기능은 여기서 구현
{
public:
	Mage(const string& n, const int h) : Character(n, h) {}

	void CastSkill()
	{
		cout << name << "이(가) 스킬을 사용합니다." << endl;
	}
};

#pragma endregion

#pragma region Is-a/Has-a 예시
class Weapon{};

class Sword :public Weapon//Is-a 관계
{
public:
	void use()
	{
		cout << "검을 사용합니다." << endl;
	}
};

class SwordMan
{
	Sword* sword;//Has-a 관계
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

	//부모 클래스의 private은 상속받은 클래스 내부에서만 접근이 가능
	//cout << c1.protectedValue << endl;

	ChildProtected c2;
	c2.ShowValues();

	//protected 상속이기 때문에 부모의 public 멤버도 부모의 protected로 받아옴
	//cout << c2.publicValue << endl;

	ChildPrivate c3;
	c3.ShowValues();

	//private 상속이기 때문에 부모의 public과 protected 멤버도 부모의 private로 취급하여 받아옴
	//cout << c3.publicValue << endl;



	Warrior* w = new Warrior("전사", 100);
	w->Attack();// 자식클래스의 멤버함수
	w->TakeDamage(10);// 부모클래스의 멤버함수
}