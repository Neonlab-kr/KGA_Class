#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#pragma region 삼항연산자 이론
/*
▶삼항연산자
- 조건식 ? 참일때의반환값 : 거짓일때의반환값
- 코드의 가독성 높이고 간결한 조건을 표현하는데 유용하게 쓰임
- 단, 조건식이 너무 복잡한 경우에는 분기문으로 처리하는편이 좋음
*/
#pragma endregion

#pragma region 문자열과 문자 이론
/*
▶ char에 대하여,,,
- char 타입은 정수를 담을 수 있다.
- 'a'는 97이라는 아스키코드 값이 담긴다.
- 한글은 1바이트를 넘기기 때문에 담기지 않는다.(UTF-8의 경우 영어 1바이트 한글 3바이트 UTF-16은 영어 2바이트 한글 2바이트)

▷ ''와 ""의 차이?
- '' 는 문자고 ""는 문자열이다.
- 문자열의 마지막에는 '\0'가 포함되어 있다.

▷ C스타일 문자열의 다양한 함수들...
1. strcpy_s(str1,str2);
2. strlen(str);
3. strcat_s(str1,str2);
4. strcmp(str1,str2);

▶String Class
- C++의 문자열 클래스
- string의 끝에는 '\0'가 들어가지 않는다.

▷String Class의 메소드들
1. length()
2. size()
3. +,=
4. ==,>,<
5. substr()
6. replace()
7. erase()

*/
#pragma endregion

void main()
{
#pragma region 삼항연산자 실습
	int num1 = 2;
	int num2 = 3;

	int result;

	result = (num1 > num2) ? num1 : num2;

	cout << result << endl;
#pragma endregion

#pragma region 문자열 실습
	char c = 'a';

	char str[] = "Hello World";
	cout << str << endl;
	cout << sizeof(str) << endl;

	//문자열 복사
	char str1[50];
	strcpy_s(str1, "Hello World");
	cout << str1 << endl;

	//문자열 길이 출력
	cout << strlen(str1) << endl;

	//문자 개별 접근
	char str2[] = "Hello";
	for (int i = 0; i < strlen(str2); i++)
	{
		cout << "문자" << i << " : " << str2[i] << endl;
	}
	cout << '\n';
	for (int i = 0; str2[i] != '\0'; i++)
	{
		cout << "문자" << i << " : " << str2[i] << endl;
	}
	cout << '\n';

	//문자열 연결하기(strcat_s)
	char str3[50] = "Hello, ";
	char str4[50] = "World";
	strcat_s(str3, str4);
	cout << str3 << endl;
	cout << '\n';

	//문자열 비교(strcmp)
	char str5[] = "Hello";
	char str6[] = "Hello";
	char str7[] = "World";
	char str8[] = "Gorld";

	int result1 = strcmp(str5, str6);
	int result2 = strcmp(str5, str7);
	int result3 = strcmp(str5, str8);

	cout <<"str5, str6 결과 : " << result1 << endl; // 0, 동일
	cout <<"str5, str7 결과 : " << result2 << endl; // -1, 앞에서 부터 비교해서 문자열의 끝에 도달할 때까지 첫문자열의 문자가 두번째 문자열의 문자보다 아스키 값이 크거나 같으면 음수
	cout <<"str5, str8 결과 : " << result3 << endl; // 1, 앞에서 부터 비교해서 문자열의 끝에 도달할 때까지 첫문자열의 문자가 두번째 문자열의 문자보다 아스키 값이 작으면 양수
	cout << '\n';
#pragma endregion

#pragma region String 클래스의 메소드
	string str9 = "Hello World";

	cout << "문자열의 길이 : " << str9.length() << endl;
	cout << '\n';

	cout << "문자열의 크기 : " << str9.size() << endl;
	cout << '\n';

	string str10 = str9;
	cout << "복사된 문자열" << str10 << endl;
	cout << '\n';


	string str11 = "Hello, ";
	string str12 = "World";
	str11 += str12;//string클래스 내부에서 +연산자가 오버로딩 되어있음.
	cout << "연결된 문자열" << str11 << endl;
	cout << '\n';


	string str13 = "Hello";
	string str14 = "Hello";
	string str15 = "World";
	string str16 = "Gorld";
	cout << "문자열 비교 " << (str13 == str14) << endl;
	cout << "문자열 비교 " << (str13 < str15) << endl;
	cout << "문자열 비교 " << (str13 > str16) << endl;
	cout << '\n';

	string str17 = "Hello, World";
	cout << "문자열 쪼개기 : " << str17.substr(7, 5) << endl;
	cout << '\n';

	cout << "문자열 대체 : " << str17.replace(7,5,"C++") << endl;
	cout << '\n';

	cout << "문자열 지우기 : " << str17.erase(5,7) << endl;
	cout << '\n';
#pragma endregion
}

/*
과제1. 함수 오버로딩을 활용한 캐릭터 스킬 만들기
- 예시
	- 스킬 이름만 입력받아 사용하는 함수
	- 스킬 이름과 데미지값을 입력받아 사용하는 함수
	- 스킬 이름, 데미지, 크리티컬 확률를 입력받아 사용하는 함수
	- 스킬 이름, 데미지, 크리티컬 확률, 사거리를 입력받아 사용하는 함수

과제2. 사용자가 입력한 양의 정수의, 각 자릿수의 합을 구하는 로직을 구현해라.
- 예시
	- 18324 -> 1+8+3+2+4 = 18
	- 3849 -> 3+8+4+9 = 24

*/