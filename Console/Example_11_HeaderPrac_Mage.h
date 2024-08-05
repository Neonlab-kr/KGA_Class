#pragma once

#include "Example_11_HeaderPrac_Unit.h"

class Mage1 :public Unit
{
public:
	Mage1(const std::string& n, const int h);

	void CastSkill();
};