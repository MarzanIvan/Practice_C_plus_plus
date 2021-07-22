#include <iostream>

using namespace std;

int main(){
double *p;
p = new double[10];
for(int i=0;i<10;i++){
	p[i] = 100 + i;
	cout << "[" << i << "] = " << p[i] << endl;	
	}
delete [] p;
return 0;
}
