
#include "include/Containers.hpp"

#include <iostream>

using namespace std;

int main() {
   int arr[10];
   Container<int> array;
   for (unsigned int i = 0; i < 10; i++ ) {
      arr[i] = i + 1;
      array.PushItem(arr[i]);
      cout << *array[i] << ' ';
   }
   for (unsigned int i = 0; i < 10; i++ ) {
      array.PullItem();
   }
   
   return 0;
}