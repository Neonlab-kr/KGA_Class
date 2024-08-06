#include<iostream>
#include "Example_12_Bike.h"
#include"Example_12_Car.h"

int main()
{
	Vehicle* v;

	v = new Car("현기차");
	v->Move();
	delete v;

	v = new Bike("오토바이");
	v->Move();
	delete v;
}