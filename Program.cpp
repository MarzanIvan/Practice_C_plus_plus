#include <iostream>

using namespace std;

void f(int size), f1(int size), build(int width, int higt);

int main(){
int len1, len2, wid1, higt1, higt2;
cout << "Enter lenght, width and higt of the brick: "; cin >> len1 >> wid1 >> higt1;
cout << "Enter lenght and higt of the hole: "; cin >> len2 >> higt2;
build(len1,higt1);build(wid1,higt1);build(len1,wid1);
if(higt1<=higt2&&wid1<=len2) cout << "Brick went to hole"; else cout << "Brick don't went ):";
return 0;
}
void build(int width, int higt){f(width); for(int i=1;i<higt;i++) f1(width); f(width);}
void f(int size){for(int i=1;i<=size;i++)cout <<'*';cout << endl;} 
void f1(int size){for(int i=1;i<=size;i++)if(i==1||i==size) cout << '*'; else cout << ' '; cout << endl;}