#pragma region 업 캐스팅 / 다운 캐스팅
/*
▷ 업 캐스팅(Up Casting)
- 자식 클래스의 객체를 부모 클래스 타입으로 변환
- 명시적인 타입 변환이 필요 없음

▷ 다운 캐스팅(Down Casting)
- 부모 클래스의 객체를 자식 클래스 타입으로 변환
- dynamic_cast<바꾸려는 새로운 타입>(대상)
*/
#pragma endregion

#pragma region 템플릿
/*
▶ 템플릿(Template)
- template <typename T>
- 아직 정해지지 않은 타입에 대해서 클래스나 함수를 정의할 수 있다!(제네릭 프로그래밍)
- 크게 함수 템플릿과 클래스 템플릿으로 나눔
- 컴파일 시점에 특정 타입으로 결정 -> 안정성
- 템플릿의 타입이름은 일회성

▷ 함수 템플릿
- 호출시 자료형에 맞는 함수를 생성하여 실행.
EX)
	template <typename T1, typename T2>
	void Output1(T1 a, T2 b)
	{
		cout << a <<", " << b << endl;
	}

▷ 클래스 템플릿
- Box2<int, double> box2; 의 형태로 객체 생성
- 호출시 자료형에 맞는 클래스를 생성하여 실행.
EX)
	template <typename T1, typename T2>
	class Box2
	{
	private:
		T1 firstData;
		T2 secondData;
	public:
		void setFirstData(T1 data) { this->firstData = data; }
		T1 getFirstData() { return firstData; }

		void setSecondData(T2 data) { this->secondData = data; }
		T1 getSecondData() { return secondData; }
	};
*/
#pragma endregion

/*
과제1. 
1. Gamescene이라는 클래스를 생성
	- 해당 scene에서 전투하는 로직을 구현하세요.

int main()
{
	GameScene game
}

[콘솔 프로젝트]
1. 콘솔 프로젝트는 개인으로 진행
2. 언어 숙지를 위한 프로젝트임
3. 과제 했던거 합치기 금지(테트리스, 스네이크게임)
4. 주제 자율
5. 가장 많이 실수하는것? -> 설계부터!!! 제발!!!!

*/