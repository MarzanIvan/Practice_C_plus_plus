#include <iostream>

using namespace std;

void clear(int n = 25);

int main(){
clear(40);/*Очистка экрана*/
return 0;
}

void clear(int n){
for(;n>0;n--)cout << endl;
	cout << "Screen cleared" << endl;
}