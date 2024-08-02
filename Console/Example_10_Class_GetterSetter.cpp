#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person
{
private:
	string name;
	int age;

public:
	string getName() const
	{
		return name;
	}

	void setName(const string& name)
	{
		this->name = name;
	}
};

int main()
{
	Person p;
	p.setName("d");
	cout << p.getName() << endl;
	return 0;
}