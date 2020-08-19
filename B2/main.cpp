#include "BaseObject.h"
#include "Tree.h"
#include "House.h"
#include "Car.h"
#include "Motorbike.h"
#include "Lib.h"

int main(int argc, char** argv) {
	list<BaseObject*> listObj;
	listObj.push_back(new Tree(0,"Tree 1", 12));
	listObj.push_back(new House(1,"House 2", 322));
	listObj.push_back(new Car(2,"Car 3", 32));
	listObj.push_back(new Motorbike(3,"Motorbike 4", 122));
	//(new Tree())->printPosition();
	for(auto obj : listObj){
		obj->move();
	}
	for(auto obj : listObj){
		cout<< "ID: "<< obj->getId() << " - Name: "<< obj->getName() << endl;
	}
	for(auto obj : listObj){
		obj->printPosition();
	}
	listObj.clear();
	return 0;
}
