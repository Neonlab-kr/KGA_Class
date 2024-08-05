#include <iostream>

class Person
{
private :
	int age;

public:
	Person(int a) : age(a) {};
	//기본 복사 생성자 형태
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
	//복사생성자 호출
	Person clone(Kim);


	// 깊은 복사
	MyArray2 arr3(10);
	arr3.SetValue(0, 1);

	MyArray2 arr4(arr3);

	std::cout << "arr3 값 : " << arr3.GetValue(0) << std::endl;
	std::cout << "arr4 값 : " << arr4.GetValue(0) << std::endl;

	arr3.SetValue(0, 2);

	std::cout << "arr3 값(변경후) : " << arr3.GetValue(0) << std::endl;
	std::cout << "arr4 값(arr3 변경된후) : " << arr4.GetValue(0) << std::endl;



	//얕은 복사
	//MyArray arr1(10);
	//arr1.SetValue(0, 42);

	//MyArray arr2(arr1);

	//std::cout << "arr1 값 : " << arr1.GetValue(0) << std::endl;
	//std::cout << "arr2 값 : " << arr2.GetValue(0) << std::endl;

	//arr1.SetValue(0, 100);

	//std::cout << "arr1 값(변경후) : " << arr1.GetValue(0) << std::endl;
	//std::cout << "arr2 값(arr1 변경된후) : " << arr2.GetValue(0) << std::endl;

	//arr1의 소멸자가 실행되고 arr2의 소멸자가 실행되면서 할당 해제할 메모리를 찾지 못해서 에러 발생
	return 0;
}