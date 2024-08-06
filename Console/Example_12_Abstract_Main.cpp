#include <iostream>
#include "Example_12_AbstractPlayer.h"

int main()
{
	AbstractPlayer* p = new AbstractPlayer("test", 200);
	p->Attack();
	p->TakeDamage(10);

	//추상 클래스는 인스턴스화 할 수 없음
	//AbstractUnit* u = new AbstractUnit("test", 200);

	return 0;
}