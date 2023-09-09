#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv){

    list<string> myStrings;
    myStrings.push_back("massimo");
    myStrings.push_front("balls");
    myStrings.push_back("hamburger");
    myStrings.push_back("snake");

    list<string>::iterator itr;
    itr = myStrings.begin();

    while (*itr != "massimo"){
        itr++;
    }

    myStrings.erase(itr);
    myStrings.pop_front();
    myStrings.pop_back();


    for (itr = myStrings.begin(); itr != myStrings.end(); ++itr){
        cout << *itr << endl;
    }
    


    return 0;
}