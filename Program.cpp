#include <iostream>
#include <cstring>

using namespace std;

void f(char *p1, char *p2, int n = -1);

int main(){
char test1[100] = "This is", test2[100] = " test.";
cout << "You look result function form include <cstring>: " << strcat(test1,test2) << endl;
strcpy(test1,"This is");
f(test1, test2, 5);
cout << "You look result my function: " << test1;
return 0;
}

void f(char *p1, char *p2, int n){
while(*p1)p1++;
if(n==-1) n = strlen(p2);
while(*p2 && n){
*p1 = *p2;
p1++;p2++;
n--;
}
*p1 = '\0';
}
