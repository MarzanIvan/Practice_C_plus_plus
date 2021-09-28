#include <iostream>
#include <cctype>

using namespace std;

class Array{
   double *array;
   int size;
   public:
   Array();
   ~Array(){ delete[] array; }
   double *getarray(){ return array;}
   void generate(){ Array();}
   double min();
   void sort();
   void show();
   double max(); 
};

void Array::sort(){
    
}

double Array::min(){
    double *p = array, min = *p;
    for(int i=0;i<size;p++,i++)if(*p<min) min = *p;
    return min;
}
double Array::max(){
    double *p = array, max = *p;
    for(int i=0;i<size;p++,i++)if(*p>max) max = *p;
    return max;
}

Array::Array(){
    double *p;
    cout << "Enter amount elements of the array: ";
    cin >> size;
    array = new double[size]; p = array;
    for(int i=0;i<size;p++,i++){
        *p = 1 + rand() % 10;
        cout << *p << ' ';
    } cout << '\n';
}

int main(){
Array obj;
cout << "Minimum = " << obj.min() << '\n' << "Maximum = " << obj.max() << endl;
return 0; 
}