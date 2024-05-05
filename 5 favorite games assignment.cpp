#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    //create a vector that stores character inputs from the player
  vector<string> favoriteGames;
    //starts the loop and asks for input from the player
  while (true) {
    cout << "\nWhat are your favorite video games!? (add/show/remove/quit)\n";
    string input;
    getline(cin, input);

      //splits the code into the 4 different inputs that the player can put into to get a result.
    if (input == "add") {
      cout << "What game would you like to add?\n";
      getline(cin, input);
      favoriteGames.push_back(input);
    } 
    //remove a specific input from the player
    else if (input == "remove") {
      string item;
      cout << "Enter the name of the item you want to remove: ";
      cin >> item;
      vector<string>::iterator iter = find(favoriteGames.begin(), favoriteGames.end(), item);
      if (iter != favoriteGames.end()) {
        favoriteGames.erase(iter);
      } else {
        cout << "I couldn't find that, sorry.\n\n";
      }
    } 
    //show the list that the player created
    else if (input == "show") {
      cout << "\nHere are your favorite games:\n";
      for (int i = 0; i < favoriteGames.size(); i += 1) {
        cout << favoriteGames[i] << "\n";
      }
    } 
    //quit out of the loop to end the program
    else if (input == "quit") {
      cout << "That list had some great games! Thank you for telling me!\n";
      break;
    }
      //enters into a new loop once the inputs are greater than or equal to 5
    if (favoriteGames.size() >= 5 + 1) 
    {
        //delete last input to limit it to 5
        favoriteGames.pop_back();            
      
        cout << "oops!!! you have reached your limit on video games! would you "
                "like to do? (show/quit)\n";
        getline(cin, input);
      
     //shows the same list from the first loop
     if (input == "show") 
    {
      cout << "\nHere are your favorite games:\n";
      for (int i = 0; i < favoriteGames.size(); i += 1) 
      {
        cout << favoriteGames[i] << "\n";
      }
    } 
         //breaks out of loop
    else if (input == "quit") 
    {
      cout << "That list had some great games! Thank you for telling me!\n";
      break;
    }
  }
  }
}
