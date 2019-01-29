#include <iostream>
#include <iomanip>
#include <cmath>
#define N 30
using namespace std;

class Solution
{
    public:
        double mypow(double x,int n);
        int mypow(int x,int n);
        double pow(double x,int n);
        int pow(int x,int n);
};
double Solution::mypow(double x,int n)
{
    if(n<0)
    {
        return 1.0/pow(x,-n);
    }
    else
    {
        return pow(x,n);
    }    
}
double Solution::pow(double x,int n)
{
    if(n==0)
    {
        return 1.0;
    }
    else
    {
        double v=pow(x,n/3);
        if(n%3==2)
        {
            return v*v*v*x*x;
        }
        else if(n%3==1)
        {
            return v*v*v*x;
        }
        else
        {
            return v*v*v;
        }
    }
}
int Solution::mypow(int x,int n)
{
    if(n<0)
    {
        return floor(1.0/pow(x,-n));
    }
    else
    {
        return pow(x,n);
    }
}
int Solution::pow(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        int v=pow(x,n/3);
        if(n%3==2)
        {
            return v*v*v*x*x;
        }
        else if(n%3==1)
        {
            return v*v*v*x;
        }
        else
        {
            return v*v*v;
        }
    }
}
int main()
{
    int x;
    cout<<"Input x:";
    cin>>x;
    Solution s;
    cout<<s.mypow(x,N)<<endl;
    return 0;
}
