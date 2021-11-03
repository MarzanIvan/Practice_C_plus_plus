#include <iostream>
#include "Moduls/classes.h"

using namespace std;

int main(){
    TypeString Fragment("LL");
    char *String = new char[20];
    strcpy(String, "HELLO");
    String - Fragment;
    cout << String;    
    return 0;
}