#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#pragma region 배열
/*

▶ 배열이란?
	- 같은 자료형을 가진 연속된 메모리 공간으로 이루어진 자료구조
	- 이런 배열은 같은 자료형을 가진 변수들이 여러개 필요할때 사용
	- 많은 양의 데이터를 처리할 때 유용

▷ 배열의 선언 방법
	- 자료형 배열이름 [배열의 길이];
	- EX)
		int myArray[10];

▷ 배열의 초기화 방법
	1. 크기를 명시하고 초기화
	EX)
		int arr[4] = {1,2,3,4};
	2. 배열의 크기를 생략하고 초기화
	EX)
		int arr[] = {1,2,3};
	3. 크기를 명시적으로 지정하고 일부 요소만 초기화
	EX)
		int arr[5] = {1,2,3}; // 나머지 요소들은 0으로 초기화됨
	4. 모든 요소를 초기화 하지 않음
	EX)
		int arr[5] = {};

▷ 배열 선언시 주의할 점
	- 배열의 인덱스는 0부터 시작함.
	- 즉 크기가 4인 배열의 경우 0~3까지의 인덱스가 유효함.
	- 유효하지 않은 인덱스에 접근할 경우 out of bounds 오류가 발생

▷ 배열의 메모리 주소
	- 배열은 연속된 메모리 공간을 가짐
	- 배열의 이름은 해당 배열의 첫 요소를 가르키는 포인터로 해석될 수 있음.
	- 배열의 이름 + sizeof(배열의 자료형) * 인덱스 번호 -> &배열의 이름[인덱스 번호] 와 같음

▷ 배열과 반복문
	- 배열은 일반적으로 for문과 함께 사용 되는 경우가 많음
	EX)
		int arr[4];
		for (int i = 0; i < 4; i++)
		{
			arr[i] = i + 1; // 순차적 값 할당
			cout << arr[i] << endl; // 순차적 값 출력
		}

▷ 실습 예제
	- 만약 10명의 학생 성적을 입력 -> 배열에 저장 -> 총점과 평균을 구하려면?
	const int student = 10;

	int sum = 0;
	int scoreArray[student];

	for (int i = 0; i < student; i++)
	{
		printf("%02d번째 학생의 성적을 입력하세요 : ", i + 1);
		cin >> scoreArray[i];
		sum += scoreArray[i];
	}
	printf("총점 : %d, 평균 : %.2f", sum, sum / static_cast<float>(student) );

▶ 다차원 배열
	- int arr1[4][3]; 같은 형태로 선언이 가능
	- 실제 주소값은 모든 배열이 선형으로 연결된 형태임.
	- n차원 배열은 n중 for문과 일반적으로 자주 사용.
	EX)
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << arr1[i][j];
			}
		}
*/
#pragma endregion


int main()
{
	int num;
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;

	int arr[4] = { 1,2,3,4 };

	printf("arr[%d]번째 데이터 : %d\n", 0, arr[0]);
	printf("arr[%d]번째 데이터 : %d\n", 1, arr[1]);
	printf("arr[%d]번째 데이터 : %d\n", 2, arr[2]);
	printf("arr[%d]번째 데이터 : %d\n", 3, arr[3]);

	cout << "===============================================" << endl;

	printf("arr[%d]번째 데이터의 주소 : %x\n", 0, &arr[0]);
	printf("arr[%d]번째 데이터의 주소 : %x\n", 1, &arr[1]);
	printf("arr[%d]번째 데이터의 주소 : %x\n", 2, &arr[2]);
	printf("arr[%d]번째 데이터의 주소 : %x\n", 3, &arr[3]);


	cout << "for문을 이용한 배열 출력" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << endl;
	}

	int number[5];

	for (int i = 0; i < 5; i++)
	{
		number[i] = i + 1;
	}

	// 만약 10명의 학생 성적을 입력 -> 배열에 저장 -> 총점과 평균을 구하려면?

	const int student = 10;

	int sum = 0;
	int scoreArray[student];

	for (int i = 0; i < student; i++)
	{
		printf("%02d번째 학생의 성적을 입력하세요 : ", i + 1);
		cin >> scoreArray[i];
		sum += scoreArray[i];
	}
	printf("총점 : %d, 평균 : %.2f", sum, sum / static_cast<float>(student));

	int arr1[4][3];

	arr1[0][0] = 1;
	arr1[0][1] = 2;
	arr1[0][2] = 3;

	arr1[1][0] = 4;
	arr1[1][1] = 5;
	arr1[1][2] = 6;

	arr1[2][0] = 7;
	arr1[2][1] = 8;
	arr1[2][2] = 9;

	arr1[3][0] = 10;
	arr1[3][1] = 11;
	arr1[3][2] = 12;

	cout << endl << endl;

	cout << "0행 출력 결과" << arr1[0][0] << " , " << arr1[0][1] << " , " << arr1[0][2] << endl;
	cout << "1행 출력 결과" << arr1[1][0] << " , " << arr1[1][1] << " , " << arr1[1][2] << endl;
	cout << "2행 출력 결과" << arr1[2][0] << " , " << arr1[2][1] << " , " << arr1[2][2] << endl;
	cout << "3행 출력 결과" << arr1[3][0] << " , " << arr1[3][1] << " , " << arr1[3][2] << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr1[i][j];
		}
	}
}

/*
	과제1. 배열 구구단
	- 인풋을 받아서 입력받은 숫자의 구구단 계산 결과를 배열에 저장하고 출력하기

	과제2. 랜덤 가로세로 합구하기
	- 5 X 5의 무작위(1 ~ 100) 수로 구성된 표에서 가로 합과 세로 합, 모든 수의 합을 구해라.

	과제3. Player VS Computer 숫자야구!
	1. Computer는 임의의 숫자 3개를 뽑는다.
	2. Player는 차례대로 3개의 숫자를 입력한다.
	3. 비교
		- 자리는 다르고 숫자가 동일하면 Ball
		- 자리도 같고 숫자도 같으면 Strike
		- 3Strike는 Out
		- 3Out시 종료
	4. 임의의 숫자는 1~10이며 플레이어가 그 외의 숫자 입력시 재입력.
*/