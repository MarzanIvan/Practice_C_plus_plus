#include <iostream>
#include <cmath>

using namespace std;

int main(){
float x, y, c;
double pi = 3.141592;
cout << "Enter X: ";
cin >> x;
cout << "Enter Y: ";
cin >> y;
x = x * pi/180;
y = y * pi/180;
c = pow(1 - sin(x)/cos(x),cos(x)/sin(x)) + cos(x-y);
cout << "Answer = " <<  c;
return 0;
}
