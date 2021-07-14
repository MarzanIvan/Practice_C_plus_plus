#include <iostream>

using namespace std;

void f(char *str);

int main(){
char str[] = "system is kind";
f(str);
return 0;
}

void f(char *str){
if(*str)f(str+1);
else return;
cout << *str;
}