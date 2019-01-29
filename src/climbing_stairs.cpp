#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    public:
        int climbing_stairs1(int &n);
        int climbing_stairs2(int &n);
        int climbing_stairs3(int &n);
        int climbing_stairs4(int &n);
};
int Solution::climbing_stairs1(int &n)
{
    //too slow
    //time complexity O(n)-->2n-3
    //space complexity O(n)--->2n-3
    if(n==1||n==2)
    {
        return n;
    }
    int p1=n-1,p2=n-2;
    return this->climbing_stairs1(p1)+this->climbing_stairs1(p2);
}
int Solution::climbing_stairs2(int &n)
{
    //time complexity O(n)
    //space complexity O(n)
    vector<int> p;
    p.push_back(1);
    p.push_back(2);
    for(int i=3;i<=n;i++)
    {
        auto it=p.end();
        int temp=*(it-1)+*(it-2);
        p.push_back(temp);
    }
    auto last=p.end();
    return *(last-1);
}
int Solution::climbing_stairs3(int &n)
{
    //time complexity O(n)
    //space complexity O(1)
    int pre=0,cur=1;
    for(int i=1;i<=n;i++)
    {
        int temp=cur;
        cur+=pre;
        pre=temp;
    }
    return cur;
}
int Solution::climbing_stairs4(int &n)
{
    //time complexity O(1)
    //space complexity O(1)
    const double s=sqrt(5);
    return floor((pow((1.0+s)/2,n+1)+pow((1.0-s)/2,n+1))/s+0.5);
}

int main()
{
    int m,result;
    Solution s;
    cout<<"Input the number of stairs:";
    cin>>m;
    result=s.climbing_stairs4(m);
    cout<<result<<endl;
    return 0;
}
