#include <iostream>

using namespace std;

int main(){
  register double x; register int c, m, a, y;
  cout << "Enter A (0 <= A < M): "; cin >> a;
  cout << "Enter Y (0 <= Y < M): "; cin >> y;
  cout << "Enter M (M >= A && Y && 2): "; cin >> m;
for(c=0;c<=m;c++){
x = (y = (a * y + c) % m, (double)(y + 1) / m);
cout << '[' << y << "] = " << x << endl;
}
return 0;
}