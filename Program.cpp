#include <iostream>
#include <cstdio>

using namespace std;

char *f(char *p, char str);

int main(){
register char *p, str;
int len;
cout << "Enter something in English: ";
gets(p);
cout << '\n' << "Enter initial letter: ";
cin >> str;
cout << "Enter length: ";
cin >> len;
p = f(p, str);
cout << "Your string: ";
for(int i=0;i<len;i++,p++) cout << *p; 
return 0;
}

char *f(char *p, char str){
char *p1;
for(p1=p;*p1;p1++) if(*p1==str)break;
  return p1;
}