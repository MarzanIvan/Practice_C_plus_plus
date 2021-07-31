#include <iostream>

using namespace std;

int main(){
  int size, total = 0;
  register int i, j, r, number;
cout << "Enter dimension matrix: ";
cin >> size;
int **mass = new int*[size], **minor = new int*[size];
for(i=0;i<size;i++){mass[i] = new int[size]; minor[i] = new int[size];} 
for(i=0;i<size;i++){
for(j=0;j<size;j++){
mass[i][j] = rand() % 10;
cout << mass[i][j] << ' ';
}cout << endl; }
//Заполнение минора
for(r=0;r<size;r++){
number = 0;
for(i=0;i<size;i++){
for(j=0;j<size;j++){
  if((r!=i)&&j){
    minor[r][number] = mass[i][j];
    number++;
  } 
}}}

//Second
for(i=0;i<size;i++){
 minor[i][0] = minor[i][0] * minor[i][3] - minor[i][2] * minor[i][1];
 minor[i][0] = minor[i][0] * mass[i][0];
}
total = minor[0][0] - minor[1][0] + minor[2][0];
cout << "\n Total = " << total;
return 0;
}