#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#pragma region 함수 오버로딩
/*
- 오버로딩의 조건
	- 매개변수의 개수나 타입 또는 순서가 다르다.
	- 반환형과 함수 이름은 같다.

- 오버로딩의 장점
	- 유지보수성과 가독성이 좋아짐
	- 코드의 유연성이 좋아짐
	- 하나의 이름으로 여러 함수를 관리할 수 있다.

*/
#pragma endregion

#pragma region 디폴트 매개변수
/*
- 매개변수에 기본값을 지정해줌.
- 전달된 값이 있으면 전달된 값을 사용.
- 없다면 디폴트 값을 사용.
- 가장 오른쪽부터 지정을 해줘야만 함.

int sum(int a, int b = 3)
{
	return a + b;
}

- 함수 오버로딩과 함께 사용시에는 주의해야함
	- 모호함이 발생될 수 있음.
*/
#pragma endregion

#pragma region inline 함수
/*
- 호출될 때 일반적인 함수의 호출 과정을 거치지 않고, 함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식의 함수
- 코드가 간단하고 호출이 잦은 함수에 inline을 해주면 좋음.
- 최근의 컴파일러는 알아서 내부적으로 인라인을 적용시켜 주기도 하는등 굳이 활용할 필요는 없다.
inline void Test(int left, int right) { return left > right ? left : right; }
*/
#pragma endregion

int sum(int a, int b);
int sum(int a, int b,int c);


void main()
{

}


int sum(int a, int b)
{
	return a + b;
}

int sum(int a, int b, int c)
{
	return a + b + c;
}