
#include <iostream>
#include <string>
using namespace std;


enum difficulty{EASY, MEDIUM, HARD};     //easy = 0, medium = 1, hard = 2;
enum shipTypes{TUGBOAT = 25, FRIGATE = 50, BATTLESHIP = 250, CARRIER = 1000};
//these can be lowercase too


class robot {
public: 
    string name = "Robbalobba";
};

class weapon{
public:
    string name = "Maace of Doom";
int damage = 20;
};
class human {
public:
    string name = "Thaddeus";
    robot buddy;
    weapon myWeapon;

    // constructor, is called when we create a human.
    human() { SayHello(); }
    void SayHello() {
        cout << "Hi! My name is " << name << " and my robot's name is " << buddy.name << ".\n";
        cout << "My Weapon's name is " << myWeapon.name << " and it does " << myWeapon.damage << " Damage.\n";
    }
};

int main() {
    cout << "Hello World!\n";

    shipTypes playerShip = TUGBOAT;
    int playerMoney = 5000;

    if(playerShip == TUGBOAT) {
        cout << "You've got a tugboat! That's cool.\n";
        playerMoney -= TUGBOAT; 
    }
    else if(playerShip == 1000){
        cout << "You've got a carrier! Wow!!\n";
    }

    shipTypes enemyShip = FRIGATE;

    if(playerShip < enemyShip){
        cout << "Hey! You've got a better ship than I do! No Fair!\n";
    }
    
    cout << "Your money is now $" << playerMoney << ".\n";




    
    human firstHuman;

    //question 2 
    weapon coolSword;
    coolSword.name = "Sword of Density";
    coolSword.damage = 9999;

    firstHuman.myWeapon = coolSword; //now the firstHuman instance has the coolsword.
    firstHuman.SayHello();

    cout << "The memmory address of fcoolSword is " << &coolSword << ".\n";
    cout << "The memory address of firstHuman.myWeapon is " << &firstHuman.myWeapon << ".\n";
}
