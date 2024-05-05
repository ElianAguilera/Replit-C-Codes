#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// classes are our own variable types.

class robot {
private:
  // define variables and functions
  // data members
  string name;
  int charge;

public:
  // member functions
  void status() {
    cout << "[robot: " << name << ", charge: " << charge << "]\n";
  }
  // constructors (like beginPlay)
  // a constructor runs when a new instance is created
  robot(string givenName = "Rob", int givenCharge = 10) {
    cout << "The constructor has been called! \n";
    name = givenName;
    charge = givenCharge;
    status();
  }
  // getters and setters
  void SetName(string givenName) { name = givenName; }
  void SetCharge(int givenCharge) {
    if (givenCharge > 0) {
      charge = givenCharge;
    } else {
      charge = 0;
    }
  }
  // getters
  string GetName() { return name; }
  int GetCharge() { return charge; }
};

int main() {

  cout << "Let's make some classes!\n";
  // creating a new variable of the type "robot" named "robalobba"
  robot robalobba; // this is where the constructor function is called.
  robalobba.SetName("Robalobba Danielson");
  robalobba.SetCharge(19);
  cout << "My robot's name is " << robalobba.GetName() << ".\n";
  cout << "My robot's charge = " << robalobba.GetCharge() << ".\n";
  robalobba.status();

  // create new robot instance and use the constructor to give it a custom name
  // and charge.
  robot DetroitBecomeHuman("Jeff", 35);

  vector<robot> bots;
  vector<string> names{"Rob", "Bob", "Artoo", "Threepio"};

  for (int i = 0; i < 10; i++) {
    string tempName = names[rand() % 4];
    int tempCharge = rand() % 5 + 5;             // range of 5-9
    bots.push_back(robot(tempName, tempCharge)); // create a new robot.
  }

  cout << "Our first bot in the list is: \n";
  bots[0].status();
} 
