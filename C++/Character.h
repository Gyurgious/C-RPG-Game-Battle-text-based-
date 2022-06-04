#include <iostream>
#include <string>
#include<fstream>



#ifndef CHARACTERH
#define CHARACTERH

using namespace std;


class Character {
public:
    Character();
    Character(string, int, int, int, int); // overloaded contructor that holds basic RPG stats
    void setName(string);
    
    void setXP(int);
    void setLevel(int);
    void setHealth(int);
    void printInfo(); // prints out all stats of a given class/character
    void addXP(int n); // adds xp based on the enemy's level. 
    void heal(); // heals the user. 
    bool isAlive(); // checks if a character is alive
    void rest(); // resets all stats according to level

     
    string getName();
    int getHealth();
    int getLevel();
    int getXP();
    int getDamage();
    int combat(const Character& target); // this function initiates the attack phase
    int specialCombat(const Character& target); // special attack

    void updateStats(); // checks if xp reaches the maximum it can gain in a level. If it reaches the maximum, this function will update the user's stats and level them up. 

protected:
    string name;
    int xp;
    int level;
    int health;
    int damage;

    int xpbar;
};

#endif

