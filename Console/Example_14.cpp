#pragma region STL(Standard Template Library)
/*
▶ STL
- 알고리즘이나 자료구조를 템플릿으로 제공하는 라이브러리
- 컨테이너(container), 반복자(iterator), 알고리즘(Algorithm), 함수객체

▷ 반복자
- 컨테이너의 원소를 가리키고 가리키는 원소에 접근하여 다음 원소를 가리키게 하는 기능

▷ 알고리즘
- 정렬, 삭제, 검색 등을 해결하는 일반화된 방법을 제공하는 함수 템플릿

▷ 컨테이너
- 객체를 보관하는 객체
- 클래스 템플릿의 형태로 구현되어있음
- 각 원소에 접근할 수 있도록 다양한 멤버함수를 제공
- 접근 방법은 직접 함수를 호출하거나 반복자(iterator)를 통해 접근

	▷ 시퀀스 컨테이너
	- 컨테이너 원소가 자신만의 삽입위치(순서)를 가지는 컨테이너
	- vector, list, deque

	▷ 연관 컨테이너
	- 저장 원소가 삽입순서와 다르게 특정 정렬기준에 의해 자동정렬되는 컨테이너
	- set, multiset, map, multimap

	▷ 비순차 컨테이너

	▷ 컨테이너 어댑터
*/
#pragma endregion

#pragma region vector
/*
▷ vector
- 메모리상 순차적으로 저장, 내부적으로 동적배열을 사용하여 크기를 자동으로 조절
- 인덱스([])를 통해 임의의 원소에 접근이 가능.
- vector의 멤버함수인 at을 사용해서 접근도 가능..
- 통상적으로 크기가 늘어날때 현재 메모리의 절반정도의 크기를 늘려줌
- 멤버 함수들
	- size() : 벡터의 원소 개수를 반환
	- capacity() : 벡터의 용량을 반환(벡터가 메모리에 할당된 크기) -> 현재 할당된 메모리에서 저장할 수 있는 최대 원소의 개수를 반환
	- push_back() : 벡터 끝에 원소를 추가
	- at() : 해당 인덱스의 원소를 반환
	- empty() : 벡터가 비어있는지 확인
	- clear() : 벡터의 모든 요소 제거, 용량은 그대로
	- front() : 벡터의 첫번째 요소 반환
	- back() : 벡터의 마지막 요소 반환
	- pop_back() : 벡터의 끝에서 요소를 제거
	- insert() : 지정한 위치에 요소를 삽입
	- erase() : 지정한 위치의 요소를 제거
	- reserve() : 벡터의 용량을 지정
	- swap() : 두 벡터를 교환
*/
#pragma endregion

#pragma region 반복자(iterator)
/*
▷ iterator
- 포인터와 비슷한 녀석
- begin() -> 시작 원소의 위치를 나타냄
- end() -> 끝의 위치를 나타냄(마지막 원소의 위치는 end()-1)
*/
#pragma endregion

/*
과제 1. 아무거나 클래스 만들어서 벡터에 저장하고 출력하기
과제 2. 상점시스템 만들기
- vector를 반드시 사용할 것
- Shop 클래스, Item 클래스, Charactor 클래스
- Charactor는 Inventory를 가지고 있어야함
- 구매/판매 처리(판매가는 구매가격의 n%)
- Inventory 에서 아이템 장착/해제가 가능
- 수량 제한(판매시 다시 증가)
- Character의 status 변화가 있고 확인이 가능할 것.

한줄조사 1. 스마트 포인터
- 자동으로 메모리를 관리해줌(delete를 통해 해제해줄 필요가 없음!)
- auto_ptr, unique_ptr, shared_ptr, weak_ptr
- auto_ptr은 문제가 있어서 권장 X
- 이를 해결한 경우가 unique_ptr
- 사용을 위해 #include <memory>
- C++ 11부터 지원

한줄조사 2. make_unique
*/
