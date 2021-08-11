#include <iostream>
#include <cmath>
using namespace std;

float findgip(float a, float b);
float f(float a, float b);
int f1(int a);
bool f2(int a);
void show(float mass[10]);
enum status{good, broke} PC;
void energy(double energ, status &PC);

int main(){
	for(int i=0;i<10;i++){
	energy(rand()%320 ,PC);
	if(PC==broke){cout << i << " PC is broke!"; break;}	
	}
/*
cout << "Enter value: "; cin >> a;
if(f2(a)) cout << a << "%2 = 0";

float AC, BC, GIP; cout << "Enter AC, BC: "; cin >> AC >> BC; 
GIP = findgip(AC, BC); cout << "Hypotinuse = " << GIP;
*/
return 0;
}

void energy(double energ, status &PC){
	if(energ>310) {PC = broke; cout << energ << endl;}	
}


void show(float mass[10]){for(int i=0;i<10;i++) cout << mass[i] << ' ';}

bool f2(int a){return !(a%2) ? 1 : 0;}

int f1(int a){int i, j;for(i=1,j=1;i<=a;j=i*j,i++);return j;}

float f(float a, float b){return a + a/100 * b;}

float findgip(float a, float b){return sqrt(a*a + b*b);}