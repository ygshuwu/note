#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class Solution
{
    public:
        int fibonacci1(int n);
        int fibonacci2(int n);
        int fibonacci3(int n);
        int fibonacci4(int n);
        int fibonacci5(int n);
        int fibonacci6(int n);
    private:
        vector<vector<int>> mut(vector<vector<int>> &t1,vector<vector<int>> &t2);
};
int Solution::fibonacci1(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    else
    {
        return fibonacci1(n-1)+fibonacci1(n-2);
    }
}
int Solution::fibonacci2(int n)
{
    vector<int> p={0,1};
    int t;
    for(int i=2;i<=n;i++)
    {
        t=p[i-1]+p[i-2];
        p.push_back(t);
    }
    return p[n];
}
int Solution::fibonacci3(int n)
{
    vector<vector<int>> c={{1,1},{1,0}};
    vector<vector<int>> m2={{1,1},{0,0}};
    if(n>2)
    {
        vector<vector<int>> temp;
        for(int i=1;i<n-2;i++)
        {
            temp=mut(c,c);
            c[0][0]=temp[0][0];
            c[0][1]=temp[0][1];
            c[1][0]=temp[1][0];
            c[1][1]=temp[1][1];
        }
        return m2[0][0]*c[0][0]+m2[0][1]*c[1][0];
    }
    else
    {
        return 1;
    }
}
int Solution::fibonacci4(int n)
{
    double x=sqrt(5);
    double result=1.0/x*(pow((1+x)/2,n)-pow((1-x)/2,n));
    return (int)result;
}
vector<vector<int>> Solution::mut(vector<vector<int>> &t1,vector<vector<int>> &t2)
{
    vector<vector<int>> r;
    const int t1_row=t1.size();
    const int t1_col=t1[0].size();
    const int t2_row=t2.size();
    const int t2_col=t2[0].size();
    if(t1_col!=t2_row)
    {
        cout<<"mutiply is illegal"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<t1_row;i++)
    {
        for(int j=0;j<t2_col;j++)
        {
            r[i][j]=0;
            for(int k=0;k<t1_col;k++)
            {
                r[i][j]+=t1[i][k]*t2[k][j];
            }
        }
    }
    return r;
}
int Solution::fibonacci5(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    if(n%2==0)
    {
        return 2*fibonacci5(n/2+1)*fibonacci5(n/2)-pow(fibonacci5(n/2),2);
    }
    else
    {
        return pow(fibonacci5(n/2),2)+pow(fibonacci5(n/2+1),2);
    }
}
int Solution::fibonacci6(int n)
{
    double x=1.0,y=1.0,a=0,b=1.0,t;
    while(n>0)
    {
        if(n&1)
        {
            t=a*x+b*y;
            a=x*(b-a)+a*y;
            b=t;
        }
        t=2*x*y-x*x;
        y=x*x+y*y;
        x=t;
        n>>=1;
    }
    return (int)a;
}

int main()
{
    int x;
    Solution s;
    cout<<"Input x:";
    cin>>x;
    cout<<s.fibonacci6(x)<<endl;
    return 0;
}
