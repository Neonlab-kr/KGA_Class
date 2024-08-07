#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//int GetMax(int x, int y)
//{
//	if (x > y)return x;
//	else return y;
//}
//
//float GetMax(float x, float y)
//{
//	if (x > y)return x;
//	else return y;
//}

template <typename T>
T GetMax(const T x, const T y)
{
	if (x > y)return x;
	else return y;
}

template <typename T>
T const& max(const T const& a, const T const& b)
{
	return a < b ? b : a;
}

template <typename T>
void Output(const T data)
{
	cout << "µ¥ÀÌÅÍ : " << data << endl;
}

template <typename T1, typename T2>
void Output1(T1 a, T2 b)
{
	cout << a <<", " << b << endl;
}

template <typename T>
class Box1
{
private:
	T data;
public:
	void setData(T data) { this->data = data; }
	T getData() { return data; }
};

template <typename T1, typename T2>
class Box2
{
private:
	T1 firstData;
	T2 secondData;
public:
	void setFirstData(T1 data) { this->firstData = data; }
	T1 getFirstData() { return firstData; }

	void setSecondData(T2 data) { this->secondData = data; }
	T2 getSecondData() { return secondData; }
};

int main()
{
	int a = 10;
	int b = 20;
	cout << max(a, b) << endl;
	cout << GetMax(a, b) << endl;

	float c = 30;
	float d = 40;
	cout << max(c, d) << endl;
	cout << GetMax(c, d) << endl;

	Output(1);
	Output(2.5);
	Output('c');
	Output("string");
	Output(true);
	Output(NULL);

	Output1(1, 1);
	Output1(1, 1.5);

	Box1<int> box1;
	Box2<int, double> box2;

	box2.setFirstData(10);
	box2.setSecondData(20.5);

	cout << box2.getFirstData() << endl;
	cout << box2.getSecondData() << endl;

	return 0;
}