#include <iostream>
#include "Example_12_AbstractPlayer.h"

int main()
{
	AbstractPlayer* p = new AbstractPlayer("test", 200);
	p->Attack();
	p->TakeDamage(10);

	//�߻� Ŭ������ �ν��Ͻ�ȭ �� �� ����
	//AbstractUnit* u = new AbstractUnit("test", 200);

	return 0;
}