#include <iostream>
#include <vector>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{

	vector<int> v1;
	vector<int> v2(10);//10���� �⺻��(0)���� �ʱ�ȭ�� ���� ����
	vector<int> v3(10, 5);//10���� ��Ҹ� 5���� �ʱ�ȭ�� ���� ����
	vector<int> v4 = { 1,2,3,4,5,6,7,8,9,10 };

	v4.push_back(11);
	cout << v4.size() << endl;

	cout << '\n';
	cout << v4.capacity() << endl;

	cout << '\n';

	for (int i = 0; i < v4.size(); i++)
	{
		cout << v4[i]<<endl;;
	}

	cout << '\n';

	for (int i = 0; i < v4.size(); i++)
	{
		cout << v4.at(i) << endl;;
	}

	cout << '\n';

	for (const int& num : v4)//C++11 ���� ����,������� for��, �����̳��� ��� ���Ҹ� ��ȸ
	{
		cout << num << endl;
	}

	cout << '\n';

	for (auto& num : v4)//auto�� �����Ϸ��� �˾Ƽ� �߷�����. ��, ������ ����. ������ Ÿ���� ����ϴ� ��쿡 ���� ����.
	{
		cout << ++num << endl;
	}

	system("cls");

	vector<int> v5;

	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	v5.push_back(4);

	v5.insert(v5.begin() + 1, 10);
	v5.erase(v5.begin() + 3);
	v5.pop_back();

	for (int& num : v5)
	{
		cout << num << endl;
	}

	system("cls");

	vector<int> v6;

	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(3);
	v6.push_back(4);
	v6.push_back(5);

	for (vector<int>::iterator iter = v6.begin(); iter < v6.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << '\n';

	for (vector<int>::iterator iter = v6.begin(); iter != v6.end(); ++iter)
	{
		cout << *iter << endl;
	}

	system("cls");

	vector<int> v7;

	v7.push_back(1);
	v7.push_back(3);
	v7.push_back(5);
	v7.push_back(7);
	v7.push_back(9);

	vector<int>::iterator iter = v7.begin();

	cout << iter[0] << endl;
	cout << *(iter + 2) << endl;

	iter += 2;
	cout << *iter << endl;

	system("cls");

	vector<int> v8;

	v8.push_back(1);
	v8.push_back(3);
	v8.push_back(5);
	v8.push_back(7);
	v8.push_back(9);

	vector<int>::reverse_iterator rIter = v8.rbegin();

	for (; rIter != v8.rend(); ++rIter)
	{
		cout << *rIter << endl;
	}

	return 0;
}