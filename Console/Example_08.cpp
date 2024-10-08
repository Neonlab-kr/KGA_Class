#pragma region 사용자 정의 자료형
/*
▶ 사용자 정의 자료형
- 1. 구조체
- 2. 공용체
- 3. 열거형
- 4. 클래스

▷ 열거형
- 관련된 상수들을 하나의 그룹으로 묶는다.
- 코드의 가독성을 높이고 의미있는 이름을 부여할 수 있다.
- 선언시 기본적으로 0부터 순차적인 값을 초기값으로 가지게 됨.
- 명시적으로 값을 할당해 줄 수도 있다. 이 경우 직접 명시된 이후의 값은 설정된 값에서 부터 순차적인 값을 가진다.
- switch ~ case와 함께 많이 사용
- 열거형 상수가 전역 스코프에 해당함
- 암시적 형변환 가능 -> 타입에 대한 안정성이 낮다.

▷ enumClass
- 자신만의 스코프를 가지고 있다. 즉, 같은 이름의 열거형 상수가 다른 열거형과 충돌하지 않는다.
- 사용시 범위지정 연산자와 함께 사용해야 한다.(::)
- 암시적 형변환 불가 -> 타입의 안정성을 보장함.

▷ 구조체
- 하나 이상의 변수를 그룹지어서 새로운 자료형을 정의
- C++은 생성자, 상속도 가능하며 메소드도 가능하다. 단, C에서는 불가능.
- 구조체에 포함된 변수를 멤버 변수, 포함된 함수를 멤버 함수라고 부른다.
- 구조체의 경우 접근제어 지시자를 따로 명시하지 않는다면 모든 변수와 함수는 public으로 선언된다.

▷ 구조체 선언
struct 구조체 이름 {구조체 내용};

▷생성자가 있는 구조체
- 반환형 없이 구조체의 이름과 동일한 함수를 구현하여 사용

*/
#pragma endregion

#pragma region 자료형 재정의
/*
▶ 자료형 재정의
- 자료형의 별칭을 생성하고 실제 자료형 이름 대신 사용

▷typedef

- 자료형 재정의는 _t로 끝내는 것을 권장
- 복잡한 자료형의 간소화 버전

EX)
	typedef int myInt_t;
	typedef unsigned long long uint64_t;

▷ using
EX)
	using Integer = int;
	using StringList = std::vector<string>;

*/

#pragma endregion

/*
과제1. 구조체를 활용 연습
- 구조체를 활용해서 가족관계를 출력해보세요

과제2. 카드게임 만들기
트럼프 카드는 52장
♧	♤	♡	◇

예를 들어서 만약 다음과 같은 카드가 나왔다면(출력)
아래와 같이 보여지는 카드는 컴퓨터가 낸다고 가정함.
♧7	♤8	♡9
	승리


조건은 자유

컴퓨터가 내는 두 카드의 범위 안에 있다면 승리. (베팅액 *2)

동일하면 베팅액 만큼 소진

범위 안에 들어오지 않는다면 베팅액 * 2 만큼 차감

조건) 한 번 사용한 카드는 버려야 됨. (사용하지 않는 것 뿐임)

17판 돌리면 끝나야 함, 한 턴에 3장 쓰니까.

그림카드는 숫자로 간주하지만 출력할 때는 알파벳으로 나와야 한다.

소지금 만원이 있다면 최소 베팅 금액이 있을 것이고, 내 소지금이 최소 베팅 금액보다 작아선 안된다.

남은  소지금이 최소 베팅 금액보다 작으면 파산






한줄조사. 구조체 메모리 padding에 대해서 조사해보기

*/