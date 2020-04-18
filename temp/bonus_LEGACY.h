#ifndef __BONUS_H__
#define __BONUS_H__

#include "constants.h"

class Bonus {
private:
    unit* bonus_unit();
protected:
    Bonus(int, int){};
    unit getCoord();
    void addBonus(const function<bool(int, int)>&);
    ~Bonus();
};






#endif