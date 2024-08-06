#include "Example_12_Bike.h"

Bike::Bike(const std::string& n):Vehicle(n)
{
	std::cout << "자식(Bike) 생성자 호출" << std::endl;
}

Bike::~Bike()
{
	std::cout << "자식(Bike) 소멸자 호출" << std::endl;
}

void Bike::Move() const
{
	std::cout << "자식(Bike) Move() 호출" << std::endl;
}
