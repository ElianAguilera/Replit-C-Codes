#include "includes.h"
using std::cout;
using std::string;

void Hello() {
   cout << "Hello! \n";
}

int triple(int num){
    return num * num * num;
}

string triple(string str){
    return str + str + str;
}
