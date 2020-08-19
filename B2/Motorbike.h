#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "DynamicObject.h"

class Motorbike : public DynamicObject
{
	public:
		Motorbike(){
		};
		Motorbike(int id, string name, float position) : DynamicObject( id,  name, position){
		};
		void printPosition();
		void move();
	protected:
};

#endif
