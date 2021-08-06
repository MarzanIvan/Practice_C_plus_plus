#include <iostream>
#include <cstring>
using namespace std;

int main(){
char *p; cout << "Enter value below hundred thousand: "; cin >> p;
for(register int i=0,j=strlen(p)-1;i<((int)strlen(p)/2);i++,j--){if(p[i]!=p[j]){cout << "Value isn't palinbrome!";return 0;}
}cout << "Value is palindrome!";
return 0;
}
