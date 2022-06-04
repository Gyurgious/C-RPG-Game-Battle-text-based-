#include <string>
#include "Character.h"

using namespace std;

#ifndef WIZARDH
#define WIZARDH


class Wizard: public Character{
public:
    Wizard();
    Wizard(string, int, int, int, int, int);
    void setMana(int);
    void printInfo();
    void updateMana();
    void rest();

    void updateStats();

    
    int getMana();


private:
    int mana;


};


#endif