#include <iostream>

using namespace std;

enum ocenk{good, bad};
struct revise{ int trouble; ocenk ball; }students[3];

int f(revise *p){
int temp;
for(temp=0;p->trouble;p++) if(p->ball==good) temp++;
return temp;	
}

int main(){
register int i; revise *p;
for(p = students,i=1;i<=3;i++,p++){cout << "Trouble of student [" << i << "]: ";cin >> p->trouble;}
for(p = students;p->trouble;p++)p->ball = p->trouble>=2?bad:good;	
	cout << "Amount a good students aqued " << f(p = students) << endl;
return 0;
}

