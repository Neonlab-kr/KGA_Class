#include "Example_11_HeaderPrac_Mage.h"

Mage1::Mage1(const std::string& n, const int h) :Unit(n, h) {}

void Mage1::CastSkill()
{
	std::cout << "마법사 스킬 사용~" << std::endl;
}
