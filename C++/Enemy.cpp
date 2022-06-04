#include <string>

#include "Character.h"
#include "Enemy.h"
#include "Knight.h"

using namespace std;


Enemy::Enemy() : Character("Monster", 1, 10, 20, 3) {
}

void Enemy::newMonster(int userLevel) {
    health = userLevel * 20;
    damage = userLevel * 4;
    xp = userLevel * 10;
}

int Enemy::getXP() {
    return xp;
}