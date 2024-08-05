#include "Example_11_HeaderPrac_Warrior.h"

Warrior1::Warrior1(const std::string& n, const int h) :Unit(n, h)
{

}

void Warrior1::Attack()
{
	std::cout << "Àü»ç°¡ °ËÀ» ÈÖµÎ¸¨´Ï´Ù." << std::endl;
}
