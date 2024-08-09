#pragma region template
/*
▷ 

*/
#pragma endregion

#pragma region 리스트
/*
▷ 리스트(List)
- 노드를 기반으로 되어있음(벡터와의 차이점을 숙지할 것)
- 임의 위치에 바로 접근이 불가능함(순차 접근만 가능)
- 탐색에 있어서 매우 느리지만 삽입과 삭제의 속도가 빠름
- 포인터와 데이터가 매 노드마다 들어가기 때문에 벡터에 비해 메모리 사용량이 크다

- 멤버 함수
	- push_back() : 리스트 끝 요소 추가
	- push_front() : 리스트 앞 요소 추가
	- pop_back() : 리스트 끝 요소 제거
	- pop_front() : 리스트 앞 요소 제거
	- insert() : 지정된 위치의 요소 삽입
	- erase() : 지정된 위치의 요소 제거
	- clear() : 모든 요소 제거
	- size() : 리스트 요소 개수 반환
	- front() : 첫번째 요소 반환
	- back() : 마지막 요소 반환
	- remove() : 지정한 값을 가지는 모든 요소 제거
	- reverse() : 리스트 순서 뒤집음
	- sort() : 정렬
*/
#pragma endregion

#pragma region 맵
/*
▷ 맵 (map)
- key와 value의 쌍(Pair)으로 구성됨.
- key는 unique라는 특성
- key의 중복을 허용하고 싶다면 multimap을 사용해야함
- 내부적으로 이진 검색 트리의 일종인 RBT(Red Black Tree)로 구성되어있음.
- 검색 속도가 매우 빠름

▷ 쌍(pair)
- 두개의 값을 묶어서 하나의 객체로 사용하는 템플릿 클래스
- 두개의 서로 다른 타입의 값을 함께 사용가능
- 페어는 두개의 멤버를 가지고 있다.
- first, second

▷ 값 추가 생성 방법
	1. value_type을 이용한 방법
		- 기본적인 키-값 쌍 타입을 나타낸다
		- pair 객체를 생성한 다음에 insert에 전달
		- 가독성이 떨어짐
		EX)
			data.insert(map<string,int>::value_type("key1",1));

	2. make_pair를 이용한 방법
		- pair객체를 생성하는 함수 템플릿
		- std::pair<T,T> 객체를 생성하여 return해줌
		- 자동으로 템플릿 인자를 추론하여 생성
		EX)
			data.insert(std::make_pair("key1", 1));

	3. pair를 이용한 방법
		- 키와 값을 명시적으로 선언해서 삽입
		EX)
			data.insert(std::pair<string, int>("key3", 3));

	4. 객체를 직접 생성하는 방법
		- 생성과 삽입이 분리되어 있기때문에 각각의 시점이 달라질 수 있음
		- 가독성이 떨어짐
		EX)
			std::pair<string, int> pt1("대한민국", 10);
			data.insert(pt1);
▷ 멤버함수
	- insert() : pair요소 삽입, 반환형은 <iterator,bool>의 pair임. first는 삽입된 요소에 대한 iterator이고 second는 삽입 성공 여부에 대한 bool값이다.
	- find() : 주어진 키를 검색하고 iterator를 반환, 키가 없으면 end()를 반환
	- count() : 주어진 키의 개수를 반환
	- clear() : 모든 요소를 삭제
	- empty() : 비어있는지 여부를 확인
	- size() : 요소의 개수를 반환
*/
#pragma endregion

/*
맵의 활용
여러 플레이어의 인벤토리 벡터를 map에 넣고 key는 플레이어의 이름을 넣는다면?
빠르게 해당 인벤토리를 조회가 가능
*/

/*
자료 조사 1: RBT에 대해서 조사

*/
