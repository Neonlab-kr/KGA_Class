#pragma once
#include "Example_12_AbstractUnit.h"

class AbstractPlayer:public AbstractUnit
{
public:
	AbstractPlayer(const std::string& n, const int h);
	~AbstractPlayer();
	virtual void Attack()const override;
	virtual void TakeDamage(int damage) override;
};

