#ifndef __FIELD_H__
#define __FIELD_H__

#include "constants.h"
#include "snake.h"
#include "bonus.h"

class Field : public Snake, public Bonus
{
private:
    char screen[HEIGHT][WIDTH];
public:
    Field();
    bool checkCoord(int, int);
    void output();
    void update(int);
    char** getScreen();
    ~Field();
};

#endif
