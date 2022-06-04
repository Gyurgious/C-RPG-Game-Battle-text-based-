#include <string>
#include "Character.h"
#include "Wizard.h"

using namespace std;



Wizard::Wizard() : Character() {
    mana = 0;
}

Wizard::Wizard(string userName, int userLevel, int userXP, int userHealth, int userDamage, int userMana) : Character(userName, userLevel, userXP, userHealth, userDamage) {
    mana = userMana;
}


void Wizard::setMana(int _mana) {
    mana = _mana;
}

int Wizard::getMana() {
    return mana;
}

void Wizard::updateMana() {
    int manaBar = level * 20;

    if (mana > 0) {
        mana -= 5;
        cout << "Mana: " << mana << endl;
    }
    else {
        cout << "out of mana! " << name << "has to recover! " << endl;
        mana += 5;
    }
}


void Wizard::rest() {
    cout << name << " takes a nap zzzzzz.....Energized for next battle!" << endl;
    health = level*15;
    mana = level*20;
}

void Wizard::updateStats() {
     int expBar = 20 * level;

    if (xp >= expBar) {
        level += 1;
        cout << name << " has leveled up!" << endl;
        xp = 0;
        damage += 8;
        health *= 2;
        printInfo();
    }

}


void Wizard::printInfo() {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "XP: " << xp <<  "/"  << level * 20 << endl;
    cout << "Health: " << health << "/" << level*15 << endl;
    cout << "Damage: " << damage << endl;
    cout << "Mana: " << mana << "/" << level*20 << endl;
}