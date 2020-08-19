#ifndef HOUSE_H
#define HOUSE_H

#include "StaticObject.h"
#include "Car.h"
#include "Motorbike.h"

class House : public StaticObject
{
	public:
		House(int id, string name, float position) : StaticObject( id,  name, position){
		};
		void printPosition();
		void move();
	protected:
		shared_ptr<Car> cars = make_shared<Car>();
		shared_ptr<Motorbike> motorbikes = make_shared<Motorbike>();
};

#endif
