#include "Example_11_HeaderPrac_Warrior.h"
#include "Example_11_HeaderPrac_Mage.h"

int main()
{
	Warrior1* w = new Warrior1("����",100);

	Mage1* m = new Mage1("������",100);

	w->Attack();
	m->TakeDamage(10);

	m->CastSkill();
	w->TakeDamage(10);
	
	return 0;
}