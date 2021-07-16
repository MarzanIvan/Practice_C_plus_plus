#include <iostream>

using namespace std;

int f(int x);
long f(long x);
double f(double x);

int main(){
cout << "module your value with type of int = " << f(-3) << endl;
cout << "module your value with type of long = " << f(-11.5) << endl;
cout << "module your value with type of double = " << f(-6L) << endl;
return 0;
}

int f(int x){
if (x<0) return -x;
else return x;
}

long f(long x){
if (x<0) return -x;
else return x;
}

double f(double x){
if (x<0) return -x;
else return x;
}
