#pragma once
#include <iostream>

class AbstractUnit abstract//추상클래스
{
protected:
	std::string name;
	int health;

public:
	AbstractUnit(const std::string& n, const int h);
	virtual ~AbstractUnit();

	//순수 가상 함수
	virtual void Attack() const = 0;
	virtual void TakeDamage(int damage) abstract;

};

