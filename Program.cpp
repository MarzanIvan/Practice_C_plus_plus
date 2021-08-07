#include <iostream>

using namespace std;

int main(){
int size; cout << "Enter the size of the array: "; cin >> size; float *mass = new float[size], total = 0;
cout << "Enter values: "; for(register int i=0;i<size;i++){cin >> mass[i]; total+=mass[i];} 
cout << "Average = " << (float)total/size; 
return 0;
}