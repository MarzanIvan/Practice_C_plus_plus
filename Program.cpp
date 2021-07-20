#include <iostream>

using namespace std;

int main(){
int x;
cout << "Enter X: ";
cin >> x;
if(x<100000 && x>9999)
	for(int i=100000,j=1;i>9;i=i/10,j++)
		cout << "Number [" << j << "] = " << (x%i)/(i/10) << endl;
return 0;
}