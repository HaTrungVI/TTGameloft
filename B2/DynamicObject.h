#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "BaseObject.h"

class DynamicObject : public BaseObject
{
	public:
		DynamicObject() : BaseObject(){
		};
		DynamicObject(int id, string name, float position) : BaseObject( id,  name,  position){
		};
	protected:
};

#endif
