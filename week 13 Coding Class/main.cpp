#include "includes.h"
#include "functions.h"
#include "robot.h"
#include "globalVars.h"

#include <fstream>         //for input and output of files.

int main() {
    ofstream file;
    file.open("file.txt");
    file << "Here is a line of text. \n";
    file.close();

    vector<string> names;


    //new variable with the type "ifstream" named "readFromFile;"
    ifstream readFromFile ("names.txt");
    string line;
    if(readFromFile.is_open()){
        while (getline(readFromFile, line))
            {
                cout << line << '\n'; 
                names.push_back(line);
            }
        readFromFile.close();
    } else {
        cout << "Could not read from file \n";
    }

    if(names.size() > 0) {
        cout << "The first name in names is " << names[0] << ".\n";
    }
    cout << "Could not read from file. \n";



    
    cout << "Hello World! \n";
     Hello();

    
    robot artoo;
    artoo.name = "R2-D2";

    cout << "Say hello to " << artoo.name << ". \n";

    cout << "here is artoo's name tripled: " << triple(artoo.name) << ". \n";
}
