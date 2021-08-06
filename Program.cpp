#include <iostream>
#include <cmath>

using namespace std;

int main(){
float a, b, h;
cout << "Enter initial values A, B, H: "; cin >> a >> b >> h;
cout << "y = ";for(register float i=a;i<=b;i=i+h){cout << pow(cos(log(i))/sin(log(i)),2) << "; ";}
return 0;
}
