#include <string>
#include "Character.h"

using namespace std;

#ifndef KNIGHTH
#define KNIGHTH


class Knight: public Character{
public:
    Knight();
    Knight(string, int, int, int, int, int);
    void setStamina(int);
    void setStaminaBar(int);
    void printInfo();
    void block();
    void updateStamina();
    void rest();

    void updateStats();

    
    int getStamina();


private:
    int stamina;

};


#endif