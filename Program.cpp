#include <iostream>

using namespace std;

int main(){
int x, y;
cout << "Enter x: "; cin >> x;
cout << "Enter y: "; cin >> y;
if(!x|!y) return 0;
if(x<0)if(y>0)cout <<"Second";else cout <<"Third"; else if(y>0)cout <<"First";else cout <<"Fourth";
cout << " quater plane";
return 0;
}