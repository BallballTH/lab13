#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
} 

void stat(const double src[],int N,double x[]){
    //Arithmetic Mean 
    double sum0 = 0;
    for(int i=0; i<N; i++){
        sum0 = sum0 + src[i];
        x[0] = sum0/N;
    }

    //Standard Deviation
    double sum1 = 0;
    for(int i=0; i<N; i++){
        sum1 = sum1 + pow(src[i]-x[0],2);
        x[1] = sqrt(sum1/N);
    }

    // Geometric Mean
    double sum2 = 1;
    for(int i=0; i<N; i++){
        sum2 = sum2*src[i];
        x[2] = pow(sum2,1.0/N);
    }

    // Harmonic Mean
    double sum3 = 0;
    for(int i=0; i<N; i++){
        sum3 = sum3+1/src[i];
        x[3] = N/sum3;
    }

    //Max
    double max = 0;
    for(int i=0; i<N; i++){
        if(src[i] > max)max=src[i];
    }
    x[4] = max;

    //min
    double min = src[0];
    for(int i=0; i<N; i++){
        if(src[i] < min)min=src[i];
    }
    x[5] = min;

}
