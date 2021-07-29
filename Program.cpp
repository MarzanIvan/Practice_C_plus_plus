#include <iostream>

using namespace std;

int main(){
int m1,n1, m2,n2;
cout << "First array, enter amount lines and columns: ";
cin >> m1 >> n1;
cout << "Second array, enter amount lines and columns: ";
cin >> m2 >> n2;
if(n1==n2|m1==m2){
register int lines = m1, columns = n1, i, j, r, temp1, temp2, temp = 0;
int **mass1 = new int*[lines], **mass2 = new int*[lines], **c = new int*[lines];
for(int i=0;i<lines;i++) mass1[i] = mass2[i] = c[i] =  new int[columns];
for(i=0;i<lines;i++){for(j=0;j<columns;j++){mass1[i][j] = mass1[i][j] = rand() % 10;}}
cout << "Array A: " << endl;
for(i=0;i<lines;i++){for(j=0;j<columns;j++){cout << mass1[i][j] << ' ';}cout << '\n';}
cout << '\n' << "Array B: " << endl;
for(i=0;i<lines;i++){for(j=0;j<columns;j++){cout << mass2[i][j] << ' ';}cout << '\n';}
for(r=0;r<lines;r++){
for(j=0;j<columns;j++){
for(i=0;i<lines;i++){
temp = (temp1 = mass1[r][i], temp2 = mass2[i][j], temp1 * temp2);
cout <<  mass1[r][i] << " * " << mass2[i][j] << " = " << temp << " | ";
}
cout << endl;
temp = (c[r][j] = temp, 0);
}
}
cout << '\n' << "A * B: " << endl;
for(i=0;i<lines;i++){for(j=0;j<columns;j++){cout << c[i][j] << ' ';}cout << '\n';}
}
return 0;
}