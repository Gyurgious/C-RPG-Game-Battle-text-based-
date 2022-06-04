#include <string>
#include "Character.h"

using namespace std;

#ifndef ARCHERH
#define ARCHERH


class Archer: public Character{
public:
    Archer();
    Archer(string, int, int, int, int, int);
    void setArrows(int);
    void printInfo();
    void updateArrows();
    void dodge();
    void rest();

    void updateStats();

    
    int getArrows();


private:
    int arrows;


};


#endif