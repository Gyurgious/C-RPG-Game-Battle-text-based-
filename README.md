# C-RPG-Game-Battle-text-based-


#include <iostream>
#include <string>
#include <fstream>

#include "Character.h"
#include "Knight.h"
#include "Enemy.h"
#include "Wizard.h"
#include "Archer.h"

  using namespace std;
  
void setDefaultStats(string selectClass, int &playerLevel, int &playerXP, int &playerHP, int &playerDMG) {
    if (selectClass == "Knight") {playerLevel = 1; playerXP = 0; playerHP = 20; playerDMG = 5;}
    if (selectClass == "Wizard") {playerLevel = 1; playerXP = 0; playerHP = 15; playerDMG = 8;}
    if (selectClass == "Archer") {playerLevel = 1; playerXP = 0; playerHP = 15; playerDMG = 3;}
}
void combatMenu() {
    cout << endl << "===========combat menu============" << endl;
    cout << "Select Choice: 1(Attack), 2(Special), 3(Heal)" << endl;
} 

void intermissionMenu() {
    cout << endl << "==========intermission menu==========" << endl;
    cout << "Select choice: 1(fight), 2(save), 3(rest), 4(show stats) 5(exit)" << endl;
}

int main() {
    string chooseClass, saveClass, sName, fileload, filename, outfile;
    int playerLevel, playerXP, playerHP, playerDMG, playerS; // used to initialize stats of a class
    bool newGame;



    cout << "load a save file?(y/n) " << endl;
    cin >> fileload;
    if (fileload == "y") {
        newGame = false;
        cout << "enter filename: " << endl;
        cin >> filename;
        ifstream fin(filename);

        if (!fin.is_open()) {
            cout << "File not found" << endl;
            return -1;
        }

        else {
            fin >> saveClass >> sName >> playerLevel >> playerXP >> playerHP >> playerDMG;
            chooseClass = saveClass;
            if (chooseClass == "Knight") {
                Knight knight(sName, playerLevel, playerXP, playerHP, playerDMG, 10);
                knight.printInfo();
            }

            if (chooseClass == "Wizard") {
                Wizard wizard(sName, playerLevel, playerXP, playerHP, playerDMG, 20);
                wizard.printInfo();
            }

            if (chooseClass == "Archer") {
                Archer archer(sName, playerLevel, playerXP, playerHP, playerDMG, 10);
                archer.printInfo();
            }
           
        }

    }

    else { newGame = true;}


    if (newGame) {

        cout << "============================" << endl;
        cout << "Choose a character: " << endl;
        cout << "Knight (wields a sword; can block attacks; medium damage)" << endl;
        cout << "Wizard (wields a staff; can cast special ability; high damage)" << endl;
        cout << "Archer (wields a bow; can dodge attacks; low damage)" << endl;
        cout <<"============================" << endl;

        cin >> chooseClass;
        cout << "selected class: " << chooseClass << endl;
        cout <<"============================" << endl;
        cout << "please enter a name: " << endl;
        cin >> sName;
        cout <<"============================" << endl;

        setDefaultStats(chooseClass, playerLevel, playerXP, playerHP, playerDMG); // sets default stats for each class
    }

    

    // game start
    int combatChoice, intermissionChoice; 
    Enemy monster;

    if (chooseClass == "Knight") { 
        Knight knight(sName, playerLevel, playerXP, playerHP, playerDMG, 10);

        while (knight.isAlive()) { // game loop continues while user is alive
            monster.newMonster(knight.getLevel());
            intermissionMenu();
            cin >> intermissionChoice;

            // combat phase
            if (intermissionChoice == 1) {
                cout << "battle begins!" << endl;
                while (knight.isAlive() && monster.isAlive()) {
                    combatMenu();
                    cin >> combatChoice;
                    
                    if (combatChoice == 1) {
                        while (knight.getStamina() > 0) {
                            cout << knight.getName() << " swings their sword at " << monster.getName();
                            monster.combat(knight);
                            break;
                        }
                        
                        knight.updateStamina();

                        if (monster.isAlive()) {
                            cout << monster.getName() << " fights back!";
                            knight.combat(monster);
                        }
                        else {
                            int exp =  monster.getXP();  // monster is defeated. XP is gained.
                            cout << monster.getName() << " has died! you earned " << exp << " XP!" << endl;
                            knight.addXP(exp);
                            knight.updateStats(); // system checks for level up. 
                        }
        
                        
                    }
                    if (combatChoice == 2) {
                        cout << monster.getName() << " attacks!" << endl;
                        knight.block();
                    }
                    if (combatChoice == 3) {
                        knight.heal();
                        cout << monster.getName() << " attacks while you're healing!";
                        knight.combat(monster);
                    }
                }
            
                }
                // saving the game
            if (intermissionChoice == 2) { 
                ofstream fout;

                cout << "Name save file: " << endl;
                cin >> outfile;

                fout.open(outfile);
 
                saveClass = chooseClass;
                playerLevel = knight.getLevel();
                playerXP = knight.getXP();
                playerHP = knight.getHealth();
                playerDMG = knight.getDamage();

                cout << "Player data saved!" << endl;

                fout << saveClass << " " << sName << " " << playerLevel << " " << playerXP <<  " " << playerHP << " " << playerDMG;
                fout.close();
            } 

            // user resets stats according to level
            if (intermissionChoice == 3) {
                knight.rest();
            }
            // printing out stats
            if (intermissionChoice == 4) {knight.printInfo();}

            if (intermissionChoice == 5) {cout << "game exited!" << endl; break;}
        }

        if (!knight.isAlive()) {cout << knight.getName() << " has fallen in combat! game over." << endl;}
        
    }


    // wizard class
     if (chooseClass == "Wizard") {
        Wizard wizard(sName, playerLevel, playerXP, playerHP, playerDMG, 20);

        while (wizard.isAlive()) {
            monster.newMonster(wizard.getLevel());
            intermissionMenu();
            cin >> intermissionChoice;

            // combat phase
            if (intermissionChoice == 1) {
                cout << "battle begins!" << endl;
                while (wizard.isAlive() && monster.isAlive()) {
                    combatMenu();
                    cin >> combatChoice;
                    
                    if (combatChoice == 1) {
                        while (wizard.getMana() > 0) {
                            cout << wizard.getName() << " sends a firebolt at " << monster.getName();
                            monster.combat(wizard);
                            break;
                        }
                        
                        wizard.updateMana();

                        if (monster.isAlive()) {
                            cout << monster.getName() << " fights back!";
                            wizard.combat(monster);
                        }
                        else {
                            int exp =  monster.getXP();  // monster is defeated. XP is gained.
                            cout << monster.getName() << " has died! you earned " << exp << " XP!" << endl;
                            wizard.addXP(exp);
                            wizard.updateStats(); // system checks for level up. 
                        }
        
                        
                    }
                    if (combatChoice == 2) {
                        while (wizard.getMana() > 0) {
                            cout << wizard.getName() << " unleashes a devastaing atack!" << endl;
                            monster.specialCombat(wizard);
                            break;
                        }
                        
                        wizard.updateMana();

                        if (monster.isAlive()) {
                            cout << monster.getName() << " fights back!";
                            wizard.combat(monster);
                        }
                        else {
                            int exp =  monster.getXP();  // monster is defeated. XP is gained.
                            cout << monster.getName() << " has died! you earned " << exp << " XP!" << endl;
                            wizard.addXP(exp);
                            wizard.updateStats(); // system checks for level up. 
                        }


                    }
                    if (combatChoice == 3) {
                        wizard.heal();
                        cout << monster.getName() << " attacks while you're healing!";
                        wizard.combat(monster);
                    }
                }
            
                }
                // exiting the game
            if (intermissionChoice == 2) { 
                ofstream fout;

                cout << "Name save file: " << endl;
                cin >> outfile;

                fout.open(outfile);

                saveClass = chooseClass;
                playerLevel = wizard.getLevel();
                playerXP = wizard.getXP();
                playerHP = wizard.getHealth();
                playerDMG = wizard.getDamage();

                cout << "Player data saved!" << endl;

                fout << saveClass << " " << sName << " " << playerLevel << " " << playerXP <<  " " << playerHP << " " << playerDMG;
                fout.close();
            }

            // user resets stats according to level
            if (intermissionChoice == 3) {
                wizard.rest();
            }
            // printing out stats
            if (intermissionChoice == 4) {wizard.printInfo();}

            if (intermissionChoice == 5) {cout << "game exited!" << endl; break;}
        }   

        if (!wizard.isAlive()) {
            cout << wizard.getName() << " has fallen in combat! game over." << endl;
        }
        
    }

    
    // archer class
    if (chooseClass == "Archer") {
        Archer archer(sName, playerLevel, playerXP, playerHP, playerDMG, 10);

        while (archer.isAlive()) {
            monster.newMonster(archer.getLevel());
            intermissionMenu();
            cin >> intermissionChoice;

            // combat phase
            if (intermissionChoice == 1) {
                cout << "battle begins!" << endl;
                while (archer.isAlive() && monster.isAlive()) {
                    combatMenu();
                    cin >> combatChoice;
                    
                    if (combatChoice == 1) {
                        while (archer.getArrows() > 0) {
                            cout << archer.getName() << " shoots an arrow at " << monster.getName();
                            monster.combat(archer);
                            break;
                        }
                        
                        archer.updateArrows();

                        if (monster.isAlive()) {
                            cout << monster.getName() << " fights back!";
                            archer.combat(monster);
                        }
                        else {
                            int exp =  monster.getXP();  // monster is defeated. XP is gained.
                            cout << monster.getName() << " has died! you earned " << exp << " XP!" << endl;
                            archer.addXP(exp);
                            archer.updateStats(); // system checks for level up. 
                        }
        
                        
                    }
                    if (combatChoice == 2) {
                        cout << monster.getName() << " attacks!" << endl;
                        archer.dodge();
                    }
                    if (combatChoice == 3) {
                        archer.heal();
                        cout << monster.getName() << " attacks while you're healing!";
                        archer.combat(monster);
                    }
                }
            
                }
                // exiting the game
            if (intermissionChoice == 2) { 
                ofstream fout;

                cout << "Name save file: " << endl;
                cin >> outfile;

                fout.open(outfile);

                saveClass = chooseClass;
                playerLevel = archer.getLevel();
                playerXP = archer.getXP();
                playerHP = archer.getHealth();
                playerDMG = archer.getDamage();

                cout << "Player data saved!" << endl;

                fout << saveClass << " " << sName << " " << playerLevel << " " << playerXP <<  " " << playerHP << " " << playerDMG;
                fout.close();
            }

            // user resets stats according to level
            if (intermissionChoice == 3) {
                archer.rest();
            }
            // printing out stats
            if (intermissionChoice == 4) {archer.printInfo();}

            if (intermissionChoice == 5) {cout << "game exited!" << endl; break;}
        }

        if (!archer.isAlive()) {
            cout << archer.getName() << " has fallen in combat! game over." << endl;
        }
        
    }

}
