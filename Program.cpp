#include <iostream>

using namespace std;

int *f(int *p);

int main(){
int mass[10], *p;
for(int i=0;i<10;i++){
p = &mass[i];
*p = 1 + rand() % 15;
cout << *p << ' ';
}
p = f(&mass[0]);
cout << '\n' << "Minimum value array = " << *p;
return 0;
}

int *f(int *p){
int *p1 = p;
while (*p){
if(*p<*p1) p1 = p;
p++;
}
return p1;
}
