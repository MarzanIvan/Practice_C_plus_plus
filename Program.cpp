#include <iostream>

using namespace std;

double &get(int i); 
double &place(int i); 

double value[10];
double error = -1;


int main(){

place(0) = 23.4;
place(4) = 23.4;
place(9) = 23.4;
place(12) = 12;
return 0;
}

double &get(int i){
if (i>-1 && i<10) return value[i];
else{
	cout << '\n' << "Error!!! \n You are trying to overstep the bounds of the array" << endl;
	return error;
}
}

double &place(int i){
if (i>-1 && i<10) return value[i];
else{
	cout << '\n' << "Error!!! \n You are trying to overstep the dounds of the array" << endl;
	return error;
}
}