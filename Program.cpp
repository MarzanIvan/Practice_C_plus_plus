#include <iostream>

using namespace std;

int fact(int n);

int main(){
int n;
cout << "Enter value for find factorial: " << endl;
cin >> n;
cout << n << "! = ";
cout << fact(n) << endl;
return 0;
}

int fact(int n){
int x;
if (n==1) return(1);
x = fact(n-1) * n;
return (x);
}