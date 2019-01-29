#include <iostream>
#include <cmath>
#define N 100000
using namespace std;

double f(double x)
{
    return 3.0*exp(x)+7.0;
}
double rectangle(double a,double b)
{
    const double h=(b-a)/N;
    double sum=0.0;
    for(int k=0;k<N;k++)  sum+=f(a+k*h)*h;
    return sum;
}
double trapezium(double a,double b)
{
    const double h=(b-a)/N;
    double sum=0.0;
    for(int k=0;k<N;k++)  sum+=(f(a+k*h)+f(a+k*h+h))/2*h;
    return sum;
}
double simpson(double a,double b)
{
    const double h=(b-a)/N;
    double sum=0.0;
    for(int k=0;k<N;k++)  sum+=(f(a+k*h)+4*f(a+k*h+h/2)+f(a+k*h+h))/6*h;
    return sum;
}
double romberg(double a,double b)
{
    const double h=(b-a)/N;
    double sum=0.0;
    for(int k=0;k<N;k++)  sum+=(f(a*k*h)+3*f(a+k*h+h/3)+3*f(a+k*h+2*h/3)+f(a+h*k+h))/8*h;
    return sum;
}
double boole(double a,double b)
{
    const double h=(b-a)/N;
    double sum=0.0;
    for(int k=0;k<N;k++)  sum+=(7*f(a+k*h)+32*f(a+k*h+h/4)+12*f(a+h*k+h/2)+32*f(a+h*k+3*h/4)+7*f(a+h*k+h))*h/90;
    return sum;
}

int main()
{
    cout<<rectangle(1.0,5.0)<<endl;
    cout<<trapezium(1.0,5.0)<<endl;
    cout<<simpson(1.0,5.0)<<endl;
    cout<<romberg(1.0,5.0)<<endl;
    cout<<boole(1.0,5.0)<<endl;
    return 0;
}    
