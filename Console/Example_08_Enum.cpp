#include <iostream>

using std::cout;
using std::endl;

//�⺻ ���� ���
enum Color { Red, Green, White };
//enum RGB { Red, Green, White };

//������� ���� �Ҵ�
enum Direction { Left, Right = 2, Up, Down };

void main()
{
	Color color = Red;

	if (color == Red)
	{
		cout << "����" << endl;
	}
	else if (color == Green)
	{
		cout << "���" << endl;
	}


	Direction key = Left;

	switch (key)
	{
	case Left:
		cout << "�������� �̵�" << endl;
		break;
	case Right:
		cout << "���������� �̵�" << endl;
		break;
	case Up:
		cout << "�������� �̵�" << endl;
		break;
	case Down:
		cout << "�Ʒ������� �̵�" << endl;
		break;
	default:
		break;
	}

	int num = Red;//�Ͻ������� ����ȯ ����
}