#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#define FIELD_CHAR ' '
#define SNAKE_CHAR '@'

#define HEIGHT 18
#define WIDTH 18
#define START_LEN 4

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#include <list>
#include <iostream>
#include <conio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <functional>
#include "Windows.h"

using namespace std;
using checkFoo = bool(int,int);

struct unit{
	unit(int X, int Y, char fill = FIELD_CHAR){
		this->x = X; 
		this->y = Y; 
		unit_char = fill;
	}
	int x;
	int y;
	char unit_char;
};

#endif