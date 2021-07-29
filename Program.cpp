#include <iostream>
#include <cstdio>

using namespace std;

int main(){
register char *p, *p1;
int count = 0;
gets(p);
p1 = p;
while(*p1){
  if(*p1!=' '){
    while(*p1!=' ')p1++;
    count++;
  } 
p1++;
};
cout << count;
return 0;
}
