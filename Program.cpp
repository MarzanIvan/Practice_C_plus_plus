#include <iostream>

using namespace std;

int main(){
int size; register int i, j, total = 0; cout << "Enter the size of the array: "; cin >> size;
int **mass = new int*[size];for(i=0;i<size;i++)mass[i] = new int[size];
for(i=0;i<size;i++){for(j=0;j<size;j++){mass[i][j] = rand() % 50; cout << mass[i][j] << "  ";}cout << endl;}
for(i=0;i<size;i++)total+=mass[i][i];
/*Clean stack*/for(i=0;i<size;i++)delete[] mass; delete[] mass;
cout << "Total = " << total;
return 0;
}