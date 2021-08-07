#include <iostream>
#include <cmath>

using namespace std;

int main(){
register int n, i, j;float t1=0,t2=0; cout << "Enter n: "; cin >> n;
float pi = 3.1415;
for(i=1;i<=n;i++){
for(j=1;j<=i;j++)t2+=sin(j * (pi/180));
  t1+=1/t2; t2=0;	 
}cout << "Total = " << t1;
return 0;
}