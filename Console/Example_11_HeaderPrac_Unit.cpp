#include "Example_11_HeaderPrac_Unit.h"

Unit::Unit()
{
}

Unit::Unit(const std::string& n, const int h):name(n), health(h)
{
	std::cout << "�θ� Ŭ���� Unit ������ ȣ��" << std::endl;
}

Unit::~Unit()
{
	std::cout << "�θ� Ŭ���� Unit �Ҹ��� ȣ��" << std::endl;
}

void Unit::TakeDamage(const int damage)
{
	health -= damage;
	std::cout << name << "��(��) " << damage << "�� ���ظ� �Ծ���. ���� ü���� " << health << "�Դϴ�" << std::endl;
}