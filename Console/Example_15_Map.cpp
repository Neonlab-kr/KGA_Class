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

	//1. value_type을 이용한 방법
	data.insert(map<string,int>::value_type("key1",1));

	//2. make_pair를 이용한 방법
	data.insert(std::make_pair("key2", 2));

	//3. pair를 이용한 방법
	data.insert(std::pair<string, int>("key3", 3));

	//4. 객체를 직접 생성하는 방법
	std::pair<string, int> pt1("대한민국", 10);
	data.insert(pt1);

	data.erase("대한민국");

	for (std::pair<string, int> pair : data)
	{
		cout << "키값 : " << pair.first << ", 데이터 :" << pair.second << endl;
	}

	system("cls");

	map<string, int> m;
	m.insert(std::pair<string, int>("Apple", 1));
	m.insert(std::pair<string, int>("Banana", 2));
	m.insert(std::pair<string, int>("Grape", 3));

	auto res = m.insert(std::make_pair("Banana", 10));

	if (!res.second)
	{
		cout << "삽입 실패, 이미 있음. 기존 \"Banana\"를 키로 가지는 객체의 value : " << res.first->second << endl;
	}
	else
	{
		cout << "삽입 성공. \"Banana\"를 키로 가지는 객체의 value : " << res.first->second << endl;
	}

	auto iter1 = m.find("Apple");
	if (iter1 != m.end())
	{
		cout << "찾음! " << iter1->second << endl;
	}
	else
	{
		cout << "없음" << endl;
	}

	cout << "Apple : " << m.count("Apple") << endl;

	system("cls");

	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << endl;
	}

	return 0;
}