#include "CSRMatr.h"

double* CSRMatr:: rA(){     
  return A;
}

int* CSRMatr:: rjA(){
  return jA;
}


int* CSRMatr:: riA(){
  return iA;
}

int* CSRMatr:: rn(){
  return &n;
}


