#ifndef TREE_H
#define TREE_H

#include "Lib.h"
#include "StaticObject.h"

class Tree : public StaticObject
{
	public:
		Tree(int id, string name, float position) : StaticObject( id,  name, position){
		};
		void printPosition();
		void move();
	protected:
};

#endif
