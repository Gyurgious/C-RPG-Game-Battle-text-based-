#include <string>
#include "Knight.h"
#include "Character.h"

using namespace std;

Knight::Knight() : Character() {
    stamina = 0;
}

Knight::Knight(string userName, int userLevel, int userXP, int userHealth, int userDamage, int userStamina) : Character(userName, userLevel, userXP, userHealth, userDamage) {
    stamina = userStamina;
}



void Knight::block() {
    cout << name << " blocks the attack!" << endl;
}


void Knight::setStamina(int _stamina) {
    stamina = _stamina;
}

int Knight::getStamina() {
    return stamina;
}


void Knight::updateStamina() {
    int staminaBar = level * 10;

    if (stamina > 0) {
        stamina -= 2;
        cout << "Stamina: " << stamina << endl;
    }
    
    else {
        cout << "out of stamina! " << name << " has to recover! " << endl;
        stamina += 2;
    }
}

void Knight::rest() {
    cout << name << " takes a nap zzzzzz.....Energized for next battle!" << endl;
    health = level*20;
    stamina = level*10;
}

void Knight::updateStats() {
     int expBar = 20 * level;

    if (xp >= expBar) {
        level += 1;
        cout << name << " has leveled up!" << endl;
        xp = 0;
        damage += 5;
        health *= 2;
        printInfo();
    }

}


void Knight::printInfo() {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "XP: " << xp <<  "/"  << level * 20 << endl;
    cout << "Health: " << health << "/" << level*20 << endl;
    cout << "Damage: " << damage << endl;
    cout << "Stamina: " << stamina << "/" << level*10 << endl;
}