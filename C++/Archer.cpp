#include <string>
#include "Character.h"
#include "Archer.h"

using namespace std;



Archer::Archer() : Character() {
    arrows = 0;
}

Archer::Archer(string userName, int userLevel, int userXP, int userHealth, int userDamage, int userArrows) : Character(userName, userLevel, userXP, userHealth, userDamage) {
    arrows = userArrows;
}


void Archer::setArrows(int _arrows) {
    arrows = _arrows;
}

int Archer::getArrows() {
    return arrows;
}

void Archer::updateArrows() {
    int maxArrows = level * 10;

    if (arrows > 0) {
        arrows -= 1;
        cout << "Arrows: " << arrows << endl;
    }
    else {
        cout << "out of arrows! " << name << "has to recover! " << endl;
        arrows += 1;
    }
}

void Archer::dodge() {
    cout << name << " avoids the attack!" << endl;
}


void Archer::rest() {
    cout << name << " takes a nap zzzzzz.....Energized for next battle!" << endl;
    health = level*15;
    arrows = level*10;
}

void Archer::updateStats() {
     int expBar = 20 * level;

    if (xp >= expBar) {
        level += 1;
        cout << name << " has leveled up!" << endl;
        xp = 0;
        damage += 3;
        health *= 2;
        printInfo();
    }

}


void Archer::printInfo() {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "XP: " << xp <<  "/"  << level * 20 << endl;
    cout << "Health: " << health << "/" << level*15 << endl;
    cout << "Damage: " << damage << endl;
    cout << "Arrows: " << arrows << "/" << level*10 << endl;
}