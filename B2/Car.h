#ifndef CAR_H
#define CAR_H

#include "DynamicObject.h"

class Car : public DynamicObject
{
	public:
		Car(){
		};
		Car(int id, string name, float position) : DynamicObject( id,  name, position){
		};
		void printPosition();
		void move();
	protected:
};

#endif
