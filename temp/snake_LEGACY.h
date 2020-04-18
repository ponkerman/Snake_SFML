#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "constants.h"

class Snake{
private:	
	vector<unit> *snake_units;
protected:
	Snake(int, int);
	int getLen();
	void add_unit(bool (*)(int, int));
	int move(int);
	vector<unit> getCoords();
	vector<unit> getunitList();
	~Snake();
};

#endif