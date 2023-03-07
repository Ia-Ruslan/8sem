#include "CSRMatr.cpp"
#include "sparskit-wrapper.h"

#include<iostream>
double* operator*(CSRMatr A, double* x){
    double* y = new double[*A.rn()];
	#ifdef WITH_SPARSKIT
        	amux_(A.rn(), x, y, A.rA(), A.rjA(), A.riA());
		return y;
	#else
        	std::cout<<"WITH_SPARSKIT=OFF  ";
		return y;
	#endif
}



