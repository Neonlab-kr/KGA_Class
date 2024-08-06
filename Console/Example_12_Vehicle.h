#pragma once
#include <iostream>

class Vehicle
{
protected:
	std::string name;
public:
	Vehicle(const std::string& n);
	virtual ~Vehicle();

	virtual void Move() const;
};

