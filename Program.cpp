#include <iostream>

using namespace std;

void f(float speed = 0, float time = 0);

int main(){
f(13,2);
f(25,10);
f(45,4);
return 0;
}

void f(float speed, float time){
	static int a;
cout << "You went " << speed * time << "\nEarly S aqued " << a << endl;
a = speed * time;
}