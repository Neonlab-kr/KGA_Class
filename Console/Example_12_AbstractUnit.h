#pragma once
#include <iostream>

class AbstractUnit abstract//�߻�Ŭ����
{
protected:
	std::string name;
	int health;

public:
	AbstractUnit(const std::string& n, const int h);
	virtual ~AbstractUnit();

	//���� ���� �Լ�
	virtual void Attack() const = 0;
	virtual void TakeDamage(int damage) abstract;

};

