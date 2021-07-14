#include <iostream>
#include <cstring>

using namespace std;

char *f(char *find, char *str);

int main(){
char str[] = {"I love to program"}, findstr[100];
cout << str;
cout << '\n' << "Enter find word: ";
cin >> findstr;
 char *res;
res = f(findstr, str);
cout << "Find string: " << res << endl;
return 0;
}


char *f(char *find, char *str){
char *p1, *p2, *start;
for(int i=0;*str;i++){
	p1 = &str[i];
	start = p1;
	p2 = find;
while(*p2 && *p2==*start){
	p1++;
	p2++;
}
if(!*p2) return start;
}
return 0;
}
