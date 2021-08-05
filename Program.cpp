#include <iostream>

using namespace std;

int main(){
int choose, higt, width; char ch; register i, j, c, t;
cout << "Choose symbol: \n" << "1. *\n" << "2. +\n" << "3. #\n" << endl;cout << "Your choose: "; cin >> choose;
switch (choose){
	case 1: ch = '*'; break; case 2: ch = '+'; break; case 3: ch = '#'; break;
	default: {cout << "Don't found"; return 0;}
}
cout << "Enter higt: "; cin >> higt;
cout << "Enter width: "; cin >> width;
for(i=1,j=c=(width/2)+1;i<=higt;i++){
for(t=1;t<=width;t++)if(t==j||t==c) cout << ch; else cout << ' ';
if(i<(width/2)+1){j--;c++;}else{j++;c--;}
cout << endl;
}
return 0;
}
