#include <iostream>
#include <cstdlib>
#include <ctime>

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
int PlayerAdventure(){
int health = 10;
int gold = 0;
int turns = 0;

do {
    string response = askYesNo("Would you like to go adventuring?");
    if (response == "yes") {
        int orcAttack = RollDie();
        int playerBlock = RollDie();

        if (playerBlock >= orcAttack) {
            cout << "You successfully block the orc's attack and lose 1 health point. You found some gold!\n";
            health -= 1;
            gold += RollDie(10);
        } else {
            cout << "You were hit by the orc's attack and lost " << orcAttack << " health points.\n";
            health -= orcAttack;
        }

        if (health <= 0) {
            break;
        }
        turns++;
    } else {
        break;
    }

} while (true);

if (health > 0) {
    cout << "Congratulations, you're still alive!\n";
    cout << "You really should go see a doctor, but you found " << gold << " gold!\n";
    if (health < 5) {
        cout << "You should consider going to the doctor.\n";
    }
} else {
    cout << "You have perished. " << gold << " pieces of gold were found beside your body.\n";
}

return 0;
}
int main() {
    srand(time(NULL));
    
    cout << PlayerAdventure();
   
}
