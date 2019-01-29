#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int max_coins_value(vector<int> &num);
    private:
        int max(int a,int b);
};
int Solution::max_coins_value(vector<int> &num)
{
    const int n=num.size();
    vector<int> f(n,0);
    f[0]=num[0];
    f[1]=max(num[0],num[1]);
    for(int i=2;i<n;i++)
    {
        f[i]=max(num[i]+f[i-2],f[i-1]);
    }
    return f[n-1];
}
int Solution::max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    vector<int> c={1,4,6,8,12,34,76,98,123};
    Solution s;
    cout<<s.max_coins_value(c)<<endl;
    return 0;
}
