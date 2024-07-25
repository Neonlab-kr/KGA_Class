#include <iostream>

using std::cout;
using std::endl;

//기본 선언 방법
enum Color { Red, Green, White };
//enum RGB { Red, Green, White };

//명시적인 값을 할당
enum Direction { Left, Right = 2, Up, Down };

void main()
{
	Color color = Red;

	if (color == Red)
	{
		cout << "빨강" << endl;
	}
	else if (color == Green)
	{
		cout << "녹색" << endl;
	}


	Direction key = Left;

	switch (key)
	{
	case Left:
		cout << "왼쪽으로 이동" << endl;
		break;
	case Right:
		cout << "오른쪽으로 이동" << endl;
		break;
	case Up:
		cout << "위쪽으로 이동" << endl;
		break;
	case Down:
		cout << "아래쪽으로 이동" << endl;
		break;
	default:
		break;
	}

	int num = Red;//암시적으로 형변환 해줌
}