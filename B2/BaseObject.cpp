/*class BaseObject{
	public:
	private:
};*/
#include "BaseObject.h"
//#include "Lib.h"

BaseObject::BaseObject()
{
	
}
BaseObject::BaseObject(int id, string name, float position){
	this->id = id;
	this->name = name;
	this->position = position;
}

BaseObject::~BaseObject()
{
}

int BaseObject::getId(){
	return id;
}
string BaseObject::getName(){
	return name;
}
 void BaseObject::printPosition(){
	std::cout << "Pos: "<<position<< std::endl;
}
void BaseObject::move(){
	std::cout << "Object move!"<< std::endl;
}
