class CSRMatr{
private:
   int n=2;
   double A[6]={1,2,3,2,5,3};
   int iA[5]={0,2,3,4,6};
   int jA[6]={0,2,1,1,2,3};
public:
   double* rA();
   int* riA();
   int* rjA();
   int* rn();

};

double* operator* (CSRMatr A, double* x);

