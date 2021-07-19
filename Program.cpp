#include <iostream>

using namespace std;

int main(){
extern int i, j;
cout << i << ' ' << j;
return 0;
}
int i = 10, j = 10;	