#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int RollDie(int sides = 6) {
    return rand() % sides + 1;
}

string askYesNo(string question) {
    string response;
    cout << question << " (yes/no): ";
    cin >> response;
    return response;
}

enum itemType{
    weapon, consumable
};

enum playerOrEnemyType{
    enemy, player
};

class item{
public: 
    itemType type = weapon;
    int damage = 0;
    string name = "";
    int remainingUses = 0;
    int healingAmount = 0;

    // build a fancy constructor
    item(string n, itemType t){
        name = n;
        type = t;
        if(type == weapon) {
            // calculate damage 
            damage = rand() % 5 + 3;
            healingAmount = 0;
            remainingUses = 999;
        }
        
        else if(type == consumable){
            healingAmount = rand() % 5 + 1;
            damage = -healingAmount;
            remainingUses = 1;

        }
    }// end of item constructor
};

class enemyOrPlayer {
public:
    playerOrEnemyType plyrOrEnmy;
    int gold;
    int health;
    string name;
    vector<item> weapons;

    enemyOrPlayer(string p, playerOrEnemyType t){
        name = p;
        plyrOrEnmy = t;
        if (plyrOrEnmy == enemy) {
            health = 20;
        }
        else if (plyrOrEnmy == player) {
            health = 20;
            gold = rand() % 5 + 1;
        }
    }
};


string typeToString(itemType type){
    //this is a switch statement. It's like an if statement, but it
    //only has to test once! All of the possible values are mapped.
    switch(type){
        case weapon: 
            return "weapon";
            break;
        case consumable: 
            return "Consumable";
            break;
        default: 
            return "unknown";
            break;
    }
}

void Inspect( item & i){
    cout << i.name << " has damage of " << i.damage << "\n";
    cout << "It can be used " << i.remainingUses << " more times.\nIt heals for " << i.healingAmount << ", \n";
    cout << "And is of the item type " << typeToString(i.type) << ".\n\n";
}

void Encounter(enemyOrPlayer & player, enemyOrPlayer & enemy) {
    while (player.health > 0 && enemy.health > 0) {
        string response = askYesNo("Would you like to attack the enemy?");
        if (response == "yes") {
            int playerAttack = RollDie(player.weapons[0].damage);
            int enemyBlock = RollDie(enemy.weapons[0].damage);
            
            
            if (enemyBlock >= playerAttack) {
                cout << "The enemy successfully blocks your attack.\n";
            }
            else {
                cout << "You hit the enemy and deal " << playerAttack << " damage.\n";
                enemy.health -= playerAttack;
            }

            if (enemy.health <= 0) {
                cout << "You have defeated the enemy!\n";
                break;
            }

            int enemyAttack = RollDie(enemy.weapons[0].damage);
            int playerBlock = RollDie(player.weapons[0].damage);

            if (playerBlock >= enemyAttack) {
                cout << "You successfully block the enemy's attack.\n";
            }
            else {
                cout << "The enemy hits you and deals " << enemyAttack << " damage.\n";
                player.health -= enemyAttack;
            }

            if (player.health <= 0) {
                cout << "You have been defeated by the enemy!\n";
                break;
            }
        }
        else {
            if (response == "no") {
                item healthPot("Healing Potion", consumable);
                cout << "Would you like to heal or stop your adventure? \n";
                cin >> response;
                if(response == "heal"){
                    cout << "you have used your health Potion! \n" << "you restored " << healthPot.healingAmount << " HP\n\n";
                    player.health -= healthPot.healingAmount;
                   healthPot.remainingUses = 0;
                    cout << "you have " << healthPot.remainingUses << " potions left\n";
                }
                else{

                    cout << "\nsuit yourself, guess you'll die /(-_-)7 (IT SAYS YOU HEALED MORE TIMES BUT YOU HAVEN'T TRUST ME)\n\n";

                }
            }
        }
    }
}

int main(){
    cout <<"More Classes!\n";
    
    srand(time(NULL));

    enemyOrPlayer plyrOgWilly("Player", player);
    enemyOrPlayer enmyOgBert("Enemy", enemy);

    item healthPot("Healing Potion", consumable);
    Inspect(healthPot);

        vector<string> weaponNames = {
            "Excalibur",
            "Mjolnir",
            "Candy Cane",
            "Oblivion",
            "Soul Reaver",
            "Masamune",
            "Deathbringer",
            "Doomhammer",
            "Frostmourne",
            "Shadowmourne"
        };

        random_shuffle(weaponNames.begin(), weaponNames.end());

        vector<item> playerWeapons;
        vector<item> enemyWeapons;

    for(const auto & name : weaponNames){
        playerWeapons.push_back(item(name, weapon));    //create a weapon.
        Inspect(playerWeapons.back());
        enemyWeapons.push_back(item(name, weapon));
        Inspect(enemyWeapons.back());
    }

    
    plyrOgWilly.weapons = playerWeapons;
    enmyOgBert.weapons = enemyWeapons;

    Encounter(plyrOgWilly, enmyOgBert);
    

    return 0;
    }

/* HOMEWORK

create BASIC adventure functionality using the enemy class for each encounter. 

each enemy must use a weapon.

each enemy has health.

player has option of using weapon or consumable at least one encounter, to the death.

*/