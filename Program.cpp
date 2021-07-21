#include <iostream>

using namespace std;

void CC(char str);

int main(){
char letter;
do{
cin >> letter;
CC(letter);
cout << letter << "& 11011111(223) = ";
letter = letter & 223;
CC(letter);
}while(letter!='Q');

return 0;
}

void CC(char str){
	register int i, ost, chislo[15], j = 0;
	i = (int) str;
	cout << str << " ANSI code = " << (int) str;
do{
ost = i%2;
i = i/2;
chislo[j] = ost;
j++;
}while(i);
cout << " 2CC = ";
for(int i=j-1;i>=0;i--) cout << chislo[i] << ' ';
cout << endl;
}