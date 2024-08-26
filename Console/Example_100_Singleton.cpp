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


//원본 부분
template <class T>
class Singleton
{
protected:
	static T* singleton;

public:
	static T* getSing(void);
	void releaseSing(void);
};

//활용 부분
class MainGame : public Singleton<MainGame>, public std::enable_shared_from_this<MainGame>
{

};

// 템플릿 클래스는 자료형을 컴파일 타임에 정해준다
// 클래스이기 때문에 메모리 소모량이 많다
// 사용하는 사람은 편하지만 컴퓨터는 안좋아함.
// 자료형이 확정되지 않는 타입에서 자료형을 날리고 get으로 다시 잡아주겠다는 의미
// 해당 처리는 컴파일러가 해줘야 하는데 매크로를 통해서 전처리기로 넘겨서 치환시켜버리겠다.

template <class T1, class T2, class T3, class T4, class T5>
class Variants
{
public:
	std::map<T1, map<T2, T3>> data;

	Variants(T1 val1) : data(Val1, nullptr, nullptr, nullptr, nullptr) {}

	template <size_t I>
	auto getVariable() const -> decltype (std::get<I>(data)) { return std::get<I> data; }
	//decltype의 경우 템플릿으로 들어간 객체에 대해서 자료형 초기화를 해줌
};

#define MAKE_VARIANTS_1(type0, type1)\
	Variants<type0,void*, void*, void*, void*>(value1, ...)

//