#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
    public:
        double sqrt_newton(double x);
        double sqrt_bin_search(double x);
        int sqrt_newton(int x);
        int sqrt_bin_search(int x);
    private:
        double bin_search(double left,double right,double x);
};
double Solution::sqrt_newton(double x)
{
    //use newton method
    if(fabs(x)<1e-6||fabs(x-1.0)<1e-6)
    {
        return x;
    }
    else
    {
        double res=x;
        while(fabs(x/res-res)>1e-6)
        {
            res=(res+x/res)/2;
        }
        return res;
    }
}
double Solution::bin_search(double left,double right,double x)
{
    double mid;
    for(int i=0;;i++)
    {
        mid=(left+right)/2;
        if(fabs(x/mid-mid)<1e-6)
        {
            return mid;
        }
        else if(x/mid<mid)
        {
            right=mid;
        }
        else
        {
            left=mid;
        }
    }
}
double Solution::sqrt_bin_search(double x)
{
    if(fabs(x)<1e-6||fabs(x-1.0)<1e-6)
    {
        return x;
    }
    if(x<1.0)
    {
        return bin_search(x,1.0,x);
    }
    else
    {
        return bin_search(1.0,x,x);
    }
}
int Solution::sqrt_newton(int x)
{
    //newton method
    if(x==0||x==1)
    {
        return x;
    }
    double res=x;
    while(fabs(x/res-res)>1e-6)
    {
        res=(res+x/res)/2;
    }
    return (int)res;
}
int Solution::sqrt_bin_search(int x)
{
    if(x<4)
    {
        return 1;
    }
    int left=1,right=x,mid,lastmid;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(x/mid>mid)
        {
            left=mid+1;
            lastmid=mid;
        }
        else if(x/mid<mid)
        {
            right=mid-1;
            lastmid=mid;
        }
        else
        {
            return mid;
        }
    }
    return lastmid;
}

int main()
{
    double x;
    Solution s;
    cout<<"Input x:";
    cin>>x;
    cout<<s.sqrt_newton(x)<<"--->"<<x<<endl;
    return 0;
}
