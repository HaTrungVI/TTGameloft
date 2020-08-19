#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "BaseObject.h"

class StaticObject : public BaseObject
{
	public:
		StaticObject(int id, string name, float position) : BaseObject( id,  name,  position){
		};
	protected:
};

#endif
