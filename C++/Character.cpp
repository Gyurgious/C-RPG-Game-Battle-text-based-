#include <iostream>
#include <string>
#include "Character.h"
#include "Knight.h"

using namespace std;

Character::Character() {
    name = "";
    level = 0;
    xp = 0;
    health = 0;
    damage = 0;
}

Character::Character(string userName, int userLevel, int userXP, int userHealth, int userDamage) {
    name = userName;
    level = userLevel;
    xp = userXP;
    health = userHealth;
    damage = userDamage;
}


void Character::setName(string _name) {
    name = _name;
}

string Character::getName() {
    return name;
}

void Character::setHealth(int _health) {
    health = _health;
}

int Character::getHealth() {
    return health;
}

void Character::setXP(int _xp) {
    xp = _xp;
}

int Character::getXP() {
    return xp;
}

void Character::addXP(int n) {
   xp += n; 
}

int Character::getDamage() {
    int dmg = damage * level;
    return dmg;
}

bool Character::isAlive() {
    return health > 0;
}


int Character::combat(const Character &target) { 
    int damageDone = target.damage;
    health -= damageDone;

    if (health < 0) {
        health = 0;
    }

    cout << ", " << name  << " takes " << damageDone << " damage!" << endl;
    cout << name << "'s health remaining: " << health << endl << endl;

    return health;
}

int Character::specialCombat(const Character& target) {
    int specialAttack = target.damage * 2;
    health -= specialAttack;

    if (health < 0) {
        health = 0;
    }

    cout << name << " takes "<< specialAttack << " damage!" << endl;
    cout << name << "'s health remaining: " << health << endl << endl;

     return health;
}

void Character::heal() {
    int healthbar = level * 20;
    int heal = level*10;
    int calcHeal;


    if (health + heal < healthbar) { // checks for overheal
        health += heal;
    }

    else {
        calcHeal = healthbar - health;  // if overheals, compute amount healed
        health = healthbar;
        cout << name << " heals for " << calcHeal << endl;
        cout << "full HP!" << endl;
    }
}


void Character::setLevel(int _level) {
    level = _level;
}

int Character::getLevel() {
    return level;
}

void Character::printInfo() {
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "XP: " << xp << endl;
    cout << "Health: " << health << endl;
    cout <<"Damage: " << damage << endl;
}




void Character::updateStats() {
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







