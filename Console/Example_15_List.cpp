#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

int main()
{
	list<int> lst = { 1,2,3,4,5 };

	lst.push_front(0);
	lst.push_back(6);

	for (int& i : lst)
	{
		cout << i << endl;
	}

	list<int>::iterator iter = lst.begin();
	
	return 0;
}