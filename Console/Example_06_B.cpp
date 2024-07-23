#include <iostream>
#include <time.h>
#include <Windows.h>
#include <random>

using std::cin;
using std::cout;
using std::endl;

void main()
{
	srand(time(NULL));

	int number[10];

	int dest, sour, temp;

	for (int i = 0; i < 10; i++)
	{
		number[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "number[" << i << "]인덱스 : " << number[i] << endl;
	}

	cout << '\n';

	//섞어보자(random suffle)
	for (int i = 0; i < 1000; i++)
	{
		dest = rand() % 10;
		sour = rand() % 10;

		//swap
		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "number[" << i << "]인덱스 : " << number[i] << endl;
	}
	

	//메르센 트위스터를 사용시 보다 좋은 품질의 난수를 얻을 수 있음
	//#include <random>을 필요로 한다.
	std::random_device rd; //비결정문적 난수 생성기
	std::mt19937 gen(rd()); // 메르센 트위스터 난수 엔진

	for (int i = 0; i < 5; i++)
	{
		cout << gen() << ' ';
	}

	//범위 지정(보다 균일한 범위를 사용하기 위해	)
	std::uniform_int_distribution<> dist(1, 6);

	for (int i = 0; i < 10; i++)
	{
		cout << dist(gen) << ' ';
	}
}