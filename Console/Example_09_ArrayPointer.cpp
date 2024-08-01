#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++)
	{
		cout << &arr[i] << endl;
	}

	int* parr;
	int i;
	parr = arr;

	for (i = 0;i < 10; i++)
	{
		cout << "arr의 주소" << &arr[i] << endl;
		cout << "parr의 값 : " << (parr + i) << endl;
	}

	return 0;
}