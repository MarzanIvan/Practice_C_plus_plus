#include <iostream>
#include <ctime>

using namespace std;

int main(){
struct tm *pt;
time_t lt;
lt = time('\0');
pt = localtime(&lt);
cout << pt->tm_hour << ':' << pt->tm_min << ':' << pt->tm_sec;
return 0;
}
