#include <iostream>

using namespace std;

double &f(int i);
double value[] = {0.1,0.2,0.3,0.4,0.5,0.6,0};

int main(){
double *p;
for(p=value;*p;p++) cout << *p << ' ';
f(3) = 1.5;
f(1) = 1.2;
cout << endl;
for(p=value;*p;p++) cout << *p << ' ';
return 0;
}

double &f(int i){
	return value[i];
}
