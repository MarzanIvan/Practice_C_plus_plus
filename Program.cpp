#include <iostream>
#include <cmath>
using namespace std;

inline double f(int a, int b, double D){
return - b + sqrt(D) / (2 * a);
}
inline double f1(int a, int b, double D){
return - b - sqrt(D) / (2 * a);
}

inline void task(int a, int b, int c,int d,int k, double D, double x){
    double y;
    y = a * x * x + b * x + c;
    cout << "Enter D, K: "; cin >> d >> k;
    x = y / (d + k);
    y = d * x + k;
    cout << "Result = [" << x << ';' << y << ']' << endl;
}

void input(){
int a, b, c, d, k;
double x, D;
cout << "Enter A, B, C: ";cin >> a >> b >> c;
D = b*b - 4 * a * c;
if(D>0){
    cout << "D > 0" << endl;
    x = f(a,b,D);
    task(a,b,c,d,k,D,x);
    x = f1(a,b,D);
    task(a,b,c,d,k,D,x);
} else if(!D){
    cout << "D = 0" << endl;
x = f(a,b,D);
task(a,b,c,d,k,D,x);
} else {
    cout << "D < 0!";
}
}

int main(){
input();
return 0; 
}