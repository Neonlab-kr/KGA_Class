// 1.
#include <iostream>
#include <time.h>
#include <Windows.h>
// Sleep(1000): 1�ʵ��� �����.
// Sleep(500): 0.5�ʵ��� �����.

// 2.
using std::cin;
using std::cout;
using std::endl;


// 3.

/*
���𰡸� �����Ҷ��� ...

1. �ʿ��� ģ���� (���)�� �̸� ����� �� �ְ� ���縦 �صд�.
�� ���α׷��Ӵ� ����� ������ �ǰ� ����� ��ǻ�Ͱ� �����Ѵ�.

2. ������ �������� �ش�.

3. ���� ������� �ϴ� ��ɿ� ���� �������� ������ ���´�.

4. �ʿ��� ���� ���� �����.

5. ����� �� ������ �ʿ��ϴٸ� �ʱ�ȭ�� �����Ѵ�.

6. ����� ������ ���� �ݺ��� ������.

7. �ݺ��� ���ư��� ���� �ȿ��� ���α׷��� ������ �� �ִ� ����� �����Ѵ�.

8. �� ����.
*/

void main()
{
	// 5.

	srand(time(NULL));


	int comNumber;
	int myNumber;


	comNumber = rand() % 100 + 1;
	//cout << "ġƮ: " << comNumber << endl;

	while (true)
	{
		cout << "���ٿ� ����: ���ڸ� �Է��ϼ��� �ִ� (100)" << endl;
		cin >> myNumber;
		Sleep(1000);

		if (myNumber == comNumber)
		{
			cout << "ã�Ҵ�." << endl;
			Sleep(3000);
			system("cls");// clean system (ȭ�� �����)
			//break;
		}

		else if(myNumber > comNumber)
		{
			cout << "�� �� �������� ������ ���ÿ�" << endl;
		}

		else
		{
			cout << "�� �� ū���� ������ ���ÿ�" << endl;
		}

		cout << endl;
	}
}

// 4.