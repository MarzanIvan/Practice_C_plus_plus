#include <iostream>

using namespace std;

int f(register int x, register int y);

int main(){
	int a, b;
cout << "Enter value A:";
cin >> a;
cout << "Enter value B:";
cin >> b;
cout << '\n' << f(a,b);
return 0;
}

int f(register int x, register int y){
int sing;
register int temp;
if(x<0) sing = -1;
 else sing = 1;
temp = 1;
for(;y;y--) temp = temp * x;
return temp * sing;
}
