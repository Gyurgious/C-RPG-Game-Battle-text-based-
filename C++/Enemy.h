#include <string>
#include "Character.h"
#include "Knight.h"

#ifndef ENEMYH
#define ENEMYH

using namespace std;

class Enemy: public Character {

public:
    Enemy();
    int getXP();
    void newMonster(int mlevel); 
    

private:
    int XP;
};

#endif