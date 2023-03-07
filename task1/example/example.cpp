#include <iostream>
#include <stdlib.h>
#include "CSRMatr.h"

using namespace std;

int main(){

   CSRMatr A;
   double a[2] = {0,1};
   double* b= new double [*A.rn()];

   b = A * a;

   for(int i=0; i<2; i++){
      cout << b[i] << " ";
   }
   cout << endl;
   return 0;

}



