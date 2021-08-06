#include <iostream>
#include <cstring>
using namespace std;

const int size = 3;

int main(){
register int i, total = 0, choose = 0;
char names[4][100] = {" About math", " About animals" , " Present Continuons" , " Exit"},
	quest[size][100] = {"6 * ? = 12 (Answer∈N)","How many ears have human (Answer∈N)?","He's eat.. porridge"},
	answers[size][100] = {"2","2","ing"}, answ[10];
while(choose!=4){
for(i=0;i<4;i++) cout << i+1 << "." << names[i] << endl;
cout << "Choose questions: "; cin >> choose;
if(choose==4) break;
if(names[choose-1][0]=='*'){cout << "This is task is complete" << endl;continue;}
cout << quest[choose-1] << '\n' << "Your answers: ";cin >> answ; 
if(!strcmp(answ,answers[choose-1])){cout << "Good!" << endl;names[choose-1][0] = (total+=3, '*');} 	
}
cout << "Amout balls = " << total;
return 0;
}
