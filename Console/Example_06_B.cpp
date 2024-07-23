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
		cout << "number[" << i << "]�ε��� : " << number[i] << endl;
	}

	cout << '\n';

	//�����(random suffle)
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
		cout << "number[" << i << "]�ε��� : " << number[i] << endl;
	}
	

	//�޸��� Ʈ�����͸� ���� ���� ���� ǰ���� ������ ���� �� ����
	//#include <random>�� �ʿ�� �Ѵ�.
	std::random_device rd; //��������� ���� ������
	std::mt19937 gen(rd()); // �޸��� Ʈ������ ���� ����

	for (int i = 0; i < 5; i++)
	{
		cout << gen() << ' ';
	}

	//���� ����(���� ������ ������ ����ϱ� ����	)
	std::uniform_int_distribution<> dist(1, 6);

	for (int i = 0; i < 10; i++)
	{
		cout << dist(gen) << ' ';
	}
}