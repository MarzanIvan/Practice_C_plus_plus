#include <iostream>

using namespace std;

void f(int &x);

int main(){
int x = 1;
cout << "Old x = " << x << endl;
f(x);
cout << "New x = " << x << endl;
return 0;
}

void f(int &x){
x = 24;
}
