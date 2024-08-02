#pragma region 클래스
/*
▷ 객체지향 프로그래밍
- 우리가 살고있는 실제 세계가 객체들로 구성되어 있는 것처럼 소프트웨어도 객체로 구성하는 방법
- 사람, TV, 세탁기, 냉장고 등등 많은 객체가 존재함.
- 각각의 객체들은 고유한 기능을 수행하고 다른 객체들과 상호작용을 한다.

▷ 객체란?
- 클래스에서 정의한 것을 토대로 메모리(실제 저장공간)에 할당된 것으로 프로그램에서 사용되는 데이터 또는 식별자에 의해 참조되는 공간을 의미
- 변수, 자료 구조, 함수 또는 메소드가 될 수 있다.

▶ 클래스
- 객체를 정의하는 틀이나 설계도
- 객체는 설계도를 기반으로 실체화 시키는것
- 구조체의 접근제어지시자 기본값은 public이지만 클래스의 경우 private

▷ 접근 제어 지시자
- public : 객체 외부에서 모두 참조가 가능
- protected : 객체 내부 또는 해당 객체를 상속받았거나 friend인 객체에서 참조가 가능.
- private : 객체 내부에서만 참조가 가능

접근제어지시자		객체내부			객체외부			상속or친구
private					O				X				X
protected				O				X				O
public					O				O				O
*/
#pragma endregion

#pragma region Constructor(생성자)
/*
▶ 생성자란?
- 객체가 생성될 때 자동으로 호출되는 특별한 멤버 함수임.
- 객체의 초기화를 담당하고 클래스와 동일한 이름을 가지며 반환형이 없음.
- 생성자는 기본 생성자, 매개변수가 있는 생성자, 복사생성자 등이 있다.
- 정의가 되어있지 않다면 컴파일러가 자동으로 제공

▷ 생성자 멤버 초기화 리스트
- 멤버 변수가 생성되고 값을 할당하는 것보다 선언과 동시에 초기화 하는 방식이기 때문에 상대적으로 효율적이다.
- 상수와 참조 멤버 변수도 초기화가 가능(본문 내에서는 불가능)
- 생성자 매개변수 뒤에 삽입되고 : 으로 시작한 다음 초기화 할 각 변수를 쉼표로 구분하여 나열 
	EX)
		string name;
		int Atk;
		int Def;
		const int a;
		int* p;

		Moster(const string& monsterName, const int monsterAtk, const int monsterDef) : name(monsterName), Atk(monsterAtk), Def(monsterDef), a(1), p(nullptr)
		{
			//여기서 할 필요가 없음
		}
*/
#pragma endregion

#pragma region Destructor(소멸자)
/*
- 객체가 소멸될 때 자동으로 호출되는 멤버 함수
- 매개변수와 반환값이 없으며 오버로딩이 불가능
*/
#pragma endregion

#pragma region Getter/Setter
/*
- private 멤버 변수에 접근하기 위한 메소드
- 데이터 캡슐화를 보존하며 변경이 가능하다.
*/
#pragma endregion

/*
과제 1. 
- 앞서 제작했던 슬라이드, 빙고, 월남뽕(카드게임) 셋중 하나를 클래스화 시킬것.
- 동적 할당을 활용할것

과제 2. 대전게임
- 플레이어와 몬스터 각각의 클래스가 있다.
- 기본적으로 둘다 공격력, 방어력, 체력이 있음.
- 턴제 전투를 진행.
- 각각의 멤버 변수는 모두 private
- 멤버 함수는 모두 public
- 둘중 하나 사망시 종료
*/