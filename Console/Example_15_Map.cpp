#include <iostream>
#include <map>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main()
{
	map<string, int> data;
	map<string, int>::iterator iter;

	//1. value_type�� �̿��� ���
	data.insert(map<string,int>::value_type("key1",1));

	//2. make_pair�� �̿��� ���
	data.insert(std::make_pair("key2", 2));

	//3. pair�� �̿��� ���
	data.insert(std::pair<string, int>("key3", 3));

	//4. ��ü�� ���� �����ϴ� ���
	std::pair<string, int> pt1("���ѹα�", 10);
	data.insert(pt1);

	data.erase("���ѹα�");

	for (std::pair<string, int> pair : data)
	{
		cout << "Ű�� : " << pair.first << ", ������ :" << pair.second << endl;
	}

	system("cls");

	map<string, int> m;
	m.insert(std::pair<string, int>("Apple", 1));
	m.insert(std::pair<string, int>("Banana", 2));
	m.insert(std::pair<string, int>("Grape", 3));

	auto res = m.insert(std::make_pair("Banana", 10));

	if (!res.second)
	{
		cout << "���� ����, �̹� ����. ���� \"Banana\"�� Ű�� ������ ��ü�� value : " << res.first->second << endl;
	}
	else
	{
		cout << "���� ����. \"Banana\"�� Ű�� ������ ��ü�� value : " << res.first->second << endl;
	}

	auto iter1 = m.find("Apple");
	if (iter1 != m.end())
	{
		cout << "ã��! " << iter1->second << endl;
	}
	else
	{
		cout << "����" << endl;
	}

	cout << "Apple : " << m.count("Apple") << endl;

	system("cls");

	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << endl;
	}

	return 0;
}