#pragma once
#include "Example_12_Vehicle.h"

class Bike :public Vehicle
{
public:
	Bike(const std::string& n);
	~Bike();

	void Move()const override;
};

