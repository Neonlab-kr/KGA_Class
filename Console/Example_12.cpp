#pragma region 가상 함수(Vitrual Function)
/*
▷ 다형성이란?
- 객체의 속성이나 기능들이 상황에 따라 여러가지 형태를 가질 수 있는 성질

▷ 가상 함수
- 상속관계에 있는 클래스에서 부모클래스의 함수를 자식 클래스에서 재정의(오버라이딩)
- 이후 부모클래스의 포인터나 참조를 통해 자식클래스의 함수 호출
- 부모클래스의 함수에 virtual키워드를 붙히면 됨.
- 멤버에 가상함수가 존재하는 경우 해당 클래스의 소멸자에도 virtual 키워드를 붙혀줄것.
	- 붙히지 않으면 기본클래스의 소멸자만 호출되고 자식 클래스의 소멸자는 호출되지 않는다.
- 자식 클래스에서 오버라이딩 하는 경우 그냥 적어도 되지만 override 키워드를 뒤에 붙혀주어 명시적으로 표시가 가능하다.

[ 오버로딩 vs 오버라이딩? ]
- 오버로딩은 함수의 이름이 같지만 매개변수의 종류나 갯수가 다른 함수를 선언할때임
- 오버라이딩은 함수를 재정의 할때 사용되는 것임.

▷ 가상함수테이블(vtable)
- 가상함수를 가지는 클래스는 자신만의 가상함수 테이블을 가지고있음.
- 가상함수 테이블은 가상함수 포인터(vptr)를 모아둔 배열임.
- 특정 가상함수를 재정의 하는 경우 재정의된 함수를 가리키도록 해당 가상함수의 포인터가 변경됨
- 가상 함수 호출시 런타임에 해당하는 가상함수포인터가 가리키고 있는 함수가 호출되게 됨
*/
#pragma endregion

#pragma region 동적 바인딩 vs 정적 바인딩
/*
▷ 동적 바인딩
- 실행 이후에 값이 확정되면 동적 바인딩이라고 한다.
- 런타임에 호출될 함수가 결정되는 것으로, virtual 키워드를 통해 동적 바인딩하는 함수를 가상 함수라고 한다.
- 함수가 가상 함수로 선언이 되면, 포인터 변수가 실제로 가리키는 객체에 따라 호출의 대상이 결정된다.

* 실행 파일을 만들 때 바인딩 되지 않고 보류 상태 둔다.
* 실행 시간에 실제로 사용된 객체의 클래스형에 의해 호출될 함수가 결정됩니다.
* 점프할 메모리 번지를 저장하기 위한 메모리 공간(4 byte)을 가지고 있다가 런타임에 결정.

▷ 정적 바인딩
- 실행 이전에 값이 확정되면 정적 바인딩이라고 한다.
- 컴파일 타임에 호출될 함수가 결정되는 것으로, 함수는 기본적으로 정적 바인딩된다.
- 컴파일러는 선언되어있는 자료형을 보고 바인딩을 하기 때문에 실제로 가리키는 객체가 무엇이든 포인터의 자료형을 기반으로 호출의대상을 결정한다.
- 컴파일 타임에 모든게 결정되므로 속도가 빠르고 런타임 성능에 영향을 미치지 않음.

* 빌드 중에 이루어진다.

*/
#pragma endregion

#pragma region 추상 클래스와 순수 가상함수
/*
▷ 순수 가상 함수
virtual void Func1() const = 0;
virtual void Func2() const abstract;

- 위와 같이 선언만 하고 구현이 아예 되어있지 않은 가상함수를 순수 가상함수 라고 한다.
- 이는 자식 클래스에서 반드시 구현되어야만 함을 의미하게 된다.

▷ 추상 클래스
- 순수 가상함수를 한개 이상 가지고 있는 클래스
- 클래스 이름 뒤에 abstract라는 키워드를 통해 명시적으로 표시할 수 있다.
- 순수 가상함수의 존재로 인해 구현이 완료되지 않은 객체이기 때문에 인스턴스화 시킬수가 없음!
- 다른 클래스가 상속받아야하는 기본 인터페이스나 기본동작을 정의하는데에 사용.
- 다형성, 코드 재사용성

▷ 인터페이스
- 순수 가상함수만을 가지고 있는 클래스
- C++에서는 인터페이스에 대한 특별한 키워드가 존재하지 않음
*/
#pragma endregion

/*
과제 1. OOP 특성 조사
- 조사하여 파일로 제출할것(PDF)

과제 2. 클래스 전방선언 조사
- 상호참조오류를 방지하기 위함
- 컴파일러에게 미리 알려주는 방법

과제 3. 추상클래스를 활용한 3가지 캐릭터 클래스를 구현
- 기본스탯, 공격, 움직이기, 공격, 데미지 받기 등등
*/