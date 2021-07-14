#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]){
int last;
for (int i=1;i<argc;i++){
last = strlen(argv[i]);
while(last>-1){
cout << argv[i][last] << ' ';
last--;
}
cout << '\n';
}
return 0;
}

