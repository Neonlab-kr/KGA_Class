#pragma once

#include "Example_11_HeaderPrac_Unit.h"

class Warrior1:public Unit
{
public:
	Warrior1(const std::string& n, const int h);

	void Attack();
};

