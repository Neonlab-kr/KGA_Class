#include <iostream>

class Person
{
private :
	int age;

public:
	Person(int a) : age(a) {};
	//�⺻ ���� ������ ����
	Person(const Person& other) : age(other.age) {};

	void SetAge(int age) { this->age = age; };
	int GetAge() { return age; };
};

class MyArray
{
private:
	int* data;
	int size;

public:
	MyArray(int size) :size(size), data(new int[size]) {};
	~MyArray()
	{
		delete[] data;
		data = nullptr;
	}

	void SetValue(int index, int value) { data[index] = value; }
	int GetValue(int index) { return data[index]; }
};

class MyArray2
{
private:
	int* data;
	int size;

public:
	MyArray2(int size) :size(size), data(new int[size]) {};
	~MyArray2()
	{
		if(data!=nullptr) delete[] data;
		data = nullptr;
	}
	MyArray2(const MyArray2& other)
	{
		this->size = other.size;
		this->data = new int[other.size];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = other.data[i];
		}
	};

	void SetValue(int index, int value) { data[index] = value; }
	int GetValue(int index) { return data[index]; }
};

int main()
{
	Person Kim(21);
	//��������� ȣ��
	Person clone(Kim);


	// ���� ����
	MyArray2 arr3(10);
	arr3.SetValue(0, 1);

	MyArray2 arr4(arr3);

	std::cout << "arr3 �� : " << arr3.GetValue(0) << std::endl;
	std::cout << "arr4 �� : " << arr4.GetValue(0) << std::endl;

	arr3.SetValue(0, 2);

	std::cout << "arr3 ��(������) : " << arr3.GetValue(0) << std::endl;
	std::cout << "arr4 ��(arr3 �������) : " << arr4.GetValue(0) << std::endl;



	//���� ����
	//MyArray arr1(10);
	//arr1.SetValue(0, 42);

	//MyArray arr2(arr1);

	//std::cout << "arr1 �� : " << arr1.GetValue(0) << std::endl;
	//std::cout << "arr2 �� : " << arr2.GetValue(0) << std::endl;

	//arr1.SetValue(0, 100);

	//std::cout << "arr1 ��(������) : " << arr1.GetValue(0) << std::endl;
	//std::cout << "arr2 ��(arr1 �������) : " << arr2.GetValue(0) << std::endl;

	//arr1�� �Ҹ��ڰ� ����ǰ� arr2�� �Ҹ��ڰ� ����Ǹ鼭 �Ҵ� ������ �޸𸮸� ã�� ���ؼ� ���� �߻�
	return 0;
}