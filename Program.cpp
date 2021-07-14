#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
double a, b;
if (argc!=3){
	cout << "You forget enter two value\n\a";
	return 1;
}
a = atof(argv[1]);
b = atof(argv[2]);
cout << a + b;
return 0;
}