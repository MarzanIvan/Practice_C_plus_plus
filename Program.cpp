#include <iostream>

using namespace std;

int main(){
int *p, size, i;
cout << "Enter amount elements in array: ";
cin >> size;
p = new int[size];
cout << "Elements array :";
for(i=0;i<size;i++){
 p[i] = rand() % 10;
 cout << p[i] << ' '; 
}
cout << "\nAmount bites in array: " << (int) sizeof(p) * size << endl;
return 0;
}