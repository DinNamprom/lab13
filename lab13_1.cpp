#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int n, double B[]) {
    double sum=0,max=0,min=A[0];
    for (int i=0;i<n;i++) {
        sum += A[i];
    }
    B[0] = sum/n;
    sum=0;
    for (int i=0;i<n;i++) {
        sum += pow((A[i]-B[0]),2);
    }
    B[1] = sqrt(sum/(n));
    sum=0;
    for (int i=0;i<n;i++) {
        sum += log(A[i]);
    }
    B[2] = exp(sum/n);
    sum=0;
    for (int i=0;i<n;i++) {
        sum += 1/A[i];
    }
    B[3] = n/sum;
    sum=0;
    for (int i=0;i<n;i++){
        if(max>A[i]) {
            max=max;
        }else if (max<A[i]){
            max=A[i];
        }
        if(min<A[i]) {
            min=min;
        }else if (min>A[i]){
            min=A[i];
        }
    }
    B[4]=max;
    B[5]=min;
}
