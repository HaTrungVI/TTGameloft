#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include "Lib.h"
class BaseObject
{
	public:
		BaseObject();
		BaseObject(int id, string name, float position);
		~BaseObject();
		virtual int getId();
		virtual string getName();
		virtual void printPosition();
		virtual void move();
	protected:
		int id=0;
		string name="obj";
		float position=12;
};

#endif
