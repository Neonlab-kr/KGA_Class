#include <iostream>
#include <memory>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;

void AddHP(int hp, int value)
{
	hp += value;
}

void main()
{
	int hp = 100;
	AddHP(hp, 100);

	int n = 0;

	cout << hp << endl;
}


//���� �κ�
template <class T>
class Singleton
{
protected:
	static T* singleton;

public:
	static T* getSing(void);
	void releaseSing(void);
};

//Ȱ�� �κ�
class MainGame : public Singleton<MainGame>, public std::enable_shared_from_this<MainGame>
{

};

// ���ø� Ŭ������ �ڷ����� ������ Ÿ�ӿ� �����ش�
// Ŭ�����̱� ������ �޸� �Ҹ��� ����
// ����ϴ� ����� �������� ��ǻ�ʹ� ��������.
// �ڷ����� Ȯ������ �ʴ� Ÿ�Կ��� �ڷ����� ������ get���� �ٽ� ����ְڴٴ� �ǹ�
// �ش� ó���� �����Ϸ��� ����� �ϴµ� ��ũ�θ� ���ؼ� ��ó����� �Ѱܼ� ġȯ���ѹ����ڴ�.

template <class T1, class T2, class T3, class T4, class T5>
class Variants
{
public:
	std::map<T1, map<T2, T3>> data;

	Variants(T1 val1) : data(Val1, nullptr, nullptr, nullptr, nullptr) {}

	template <size_t I>
	auto getVariable() const -> decltype (std::get<I>(data)) { return std::get<I> data; }
	//decltype�� ��� ���ø����� �� ��ü�� ���ؼ� �ڷ��� �ʱ�ȭ�� ����
};

#define MAKE_VARIANTS_1(type0, type1)\
	Variants<type0,void*, void*, void*, void*>(value1, ...)

//