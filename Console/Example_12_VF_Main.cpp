#include<iostream>
#include "Example_12_Bike.h"
#include"Example_12_Car.h"

int main()
{
	Vehicle* v;

	v = new Car("������");
	v->Move();
	delete v;

	v = new Bike("�������");
	v->Move();
	delete v;
}