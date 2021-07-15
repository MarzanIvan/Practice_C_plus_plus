#include <iostream>

using namespace std;

void f(int &x, int &y);

int main(){
int a, b;
cout << "Enter A: ";
cin >> a;
cout << "Enter B: ";
cin >> b;
f(a,b);
cout << '\n' << "Changed A = " << a << endl;
cout << "Changed B = " << b << endl;
return 0;
}

void f(int &x, int &y){
int temp;
temp = x;
x = y;
y = temp;
}
