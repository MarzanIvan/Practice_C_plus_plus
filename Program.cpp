#include <iostream>

using namespace std;

double &f();
double value = 100.1;

int main(){
	double x;
cout << f();
f() = 33 + 2 - 11;
x = f();
cout << '\n' << f() << endl;
cout << " X = " << x;
return 0;
}

double &f(){
return value;
}