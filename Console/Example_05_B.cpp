#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//const
//constexpr

#pragma region 변 / 상수
/*

▶ 상수란?

- 변수와 달리 저장된 데이터를 변경 할 수 없는 공간에 붙여진 이름을 의미.
ㄴ 상수는 한번 데이터가 저장되고 나면 변경하는 것이 "일반적"으로 불가능


▷ C / C++ 언어 상수의 종류

- 리터럴 상수 (0 등과 같이 메모리적인 이름이 없는 상수)
ㄴ 이름이 없는 상수
ㄴ 리터럴 상수는 이름이 없는 상수를 의미하며 임시 값이라고 지칭한다.


- 심볼릭 상수
ㄴ 이름이 존재하는 상수
ㄴ 심볼릭 상수는 const 키워드를 통해서 선언이 가능하며 리터럴 상수와 달리 이름을 통해서 저장되어 있는 데이터를 읽어 들이는것이 가능하다.


▶ constexpr 

- C++11 상수화 키워드
ㄴ 객체 / 함수 앞에 붙일 수가 있고 해당 객체나 함수의 반환값을 "컴파일 타임"에 알 수 있다.
ㄴ C++ 17부터 람다식에도 적용 가능.

※ 컴파일 타임 확정이기 때문에 템플릿과 궁합이 좋다.


▶ readonly

- C# 에서 지원하는 상수화 키워드

- C#의 const vs readonly
const
ㄴ 초기화 이후 값을 변경할 수 없다.
ㄴ 선언하는 시점에만 초기화 가능
ㄴ 컴파일 타임 상수

readonly
ㄴ 초기화 이후 값을 변경할 수 없다.
ㄴ 단, 선언하는 시점과 생성자에서 초기화가 1번 가능하다.
ㄴ 런타임 상수

- 컴파일 타임 상수는 변수가 실제 값으로 대체되고 런타임 상수는 변수 참조 형식이기 때문에 성능과 속도를 고려하면 const가 유리하다.

- 다만 인스턴스마다 다른 값을 할당하고 싶거나 사용자 정의 자료형이라면 readonly를 사용하는게 유지보수에 더 좋다.


★★★★★
define vs const
ㄴ 매크로를 배우고 나서....


★★★★★
const VS constexpr
- const는 런타임에 확정
- constexpr는 컴파일 타임에 확정

- 오류 발견 시기가 다름.

- const는 값만 상수화 시킴(불완전 상수화)
- constexpr는 주소까지 상수화 시킴(완전 상수화)




※ 신입이 약한 파트
ㄴ 문자 / 문자열 + 상수



*/
#pragma endregion

void main()
{
	cout << "== 리터럴 상수 ==" << endl;
	cout << "정수형: " << 10 << ", " << 10L << ", " << 10LL << endl;
	cout << "실수형: " << 3.14f << ", " << 3.14 << ", " << 10LL << endl;
	cout << "문자형: " << 'A' << endl;

	printf("\n");

	// 변/상수는 생성과 동시에 값을 대입하는 것이 가능하다.
	// ㄴ 이것을 바로 초기화라고 했었다.

	// A
	int numberA = 10;

	//B
	int numberB;
	numberB = 10;

	cout << "== 심볼릭 상수 ==" << endl;

	const int nValueA = 0;
	const float fValueB = 3.14f;
	const double dbValueA = 3.14;

	cout << "출력 값 : " << nValueA << ", " << fValueB << ", " << dbValueA << endl;
	printf("%d, %f, %lf\n", nValueA, fValueB, dbValueA);

	// 상수는 다양하게 사용이 되니 꼭 숙지할것

	// 1. 둘이 똑같다.
	const int cNumberA = 100;
	int const cNumberB = 200;

	// 2. 변수명이 가르키는 주소의 값을 변경할 수 없다.
	// ㄴ 주소의 상수화
	const int* cNumberC;

	// 3.포인터 변수의 상수화(cNumberD)
	int pNum;
	int* const cNumberD = &pNum;

	// 4. 주소와 포인터 변수의 상수화
	const int* const cNumberE = &pNum;
}