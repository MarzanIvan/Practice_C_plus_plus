
#include "include/Containers.hpp"

int main() {

   int AmountObjects = 0;
   
   cout << "Enter an amount of objects: ";
   cin >> AmountObjects;
   
   int *Objects = new int[AmountObjects];
   Container <int> VectorObjects;
   
   for ( int i = 0; i < AmountObjects; i++ ) {
      VectorObjects.AddElement(Objects[i]);
   }
   
   for ( int i = 0; i < AmountObjects; i++ ) {
      VectorObjects.DeleteElement();
   }
   cout << "Good!";
   return 0;
}