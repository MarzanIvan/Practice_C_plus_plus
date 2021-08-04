#include <iostream>

using namespace std;

int main(){
register char *p = {"Good morning!\nGood weatger today\nI Would cup coffee"};
int amount = 1;
cout << "Content: \n" << p << endl;
for(int i=0;p[i];i++) if(p[i]=='\n') amount++;
cout << "Amount strings: " << amount;
return 0;
}