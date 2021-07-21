#include <iostream>

using namespace std;

void CC(char str);
void confbit(unsigned x);
void Smallletter();
void Bigletter();

int main(){
unsigned n;
n = 256;
for(int i=0;i<8;i++){
	cout << n << endl;
	confbit(n);
	n = n >> 1;
}
n=1;
for(int i=0;i<8;i++){
	cout << n << endl;
	confbit(n);
	n = n << 1;
}
return 0;
}

void Smallletter(){
char letter;
do{
cout << "Doing small letter " << endl;
cin >> letter;
CC(letter);
cout << letter << "| 100000(32) = ";
letter = letter | 32;
CC(letter);
}while(letter!='q');
}

void Bigletter(){
char letter;
do{
cout << "Doing big letter " << endl;
cin >> letter;
CC(letter);
cout << letter << "& 11011111(223) = ";
letter = letter & 223;
CC(letter);
}while(letter!='Q');	
}


void confbit(unsigned x){
register int i;
for(i=128;i>0;i=i/2){
	if(x & i)cout << " 1 ";
	else cout << " 0 ";
}
cout << endl;
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