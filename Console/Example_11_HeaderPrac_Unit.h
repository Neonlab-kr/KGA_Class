#pragma once

#include  <iostream>

class Unit
{
protected:
	std::string name;
	int health;

public:
	Unit();
	Unit(const std::string& n, const int h);
	~Unit();

	void TakeDamage(const int damage);
};



