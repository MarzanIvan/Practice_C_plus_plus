#include <iostream>

using namespace std;

int main(){
int bound, i = 0, total = 0;cout << "Enter bound: "; cin >> bound;
while(i<=bound){if(i%5==0)total+=i; i++;}
cout << "Total = " << total;
return 0;
}