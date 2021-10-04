#include <iostream>
#include <ctime>

using namespace std;

class timer{
int seconds;
public:
timer(int InSecond){ seconds = InSecond; }
timer( int sec, int min,  int hour = 0){ min += hour * 60; seconds = sec + min * 60; }
void start();
};

void timer::start(){
clock_t tm;
while(seconds>=0){
tm = clock() / CLOCKS_PER_SEC; // Получаем количество секунд работы процессора относительно этого момента
while(clock() / CLOCKS_PER_SEC - tm < 1); // Выполнение ожидания, равное одной секунде
cout << seconds << "..." << endl;
    seconds--;
}
cout << "Timer stopped" << endl;
}

int main(){
    int seconds;
    cout << "Enter an amount of the seconds: "; cin >> seconds; 
timer objtimer = seconds; // вызываем перегружаемый конструктор, принимающий только int значения
objtimer.start(); // Включение таймера
return 0;
}