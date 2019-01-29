#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
       vector<vector<int>> pascal_triangle1(int rows);
       vector<int> pascal_triangle2(int k);
};
vector<vector<int>> Solution::pascal_triangle1(int rows)
{
    //time complexity O(n^2)
    //space complexity O(n^2)
    vector<vector<int>> p;
    for(int i=0;i<rows;i++)
    {
        vector<int> q(rows,0);
        q[0]=1;
        q[i]=1;
        p.push_back(q);
    }
    for(int i=2;i<rows;i++)
    {
        for(int j=1;j<i;j++)
        {
            p[i][j]=p[i-1][j]+p[i-1][j-1];
        }
    }
    return p;
}
vector<int> Solution::pascal_triangle2(int k)
{
    //time complexity O(n^2)
    //space complexity O(n)
    //k is the rowindex
    //use rotating array!!!!!!!
    vector<int> p;
    for(int i=0;i<=k;i++)
    {
        for(int j=i-1;j>0;j--)
        {
            //don't for(int j=1;j<i;j++)
            p[j]=p[j]+p[j-1];
        }
        p.push_back(1);
    }
    return p;
}
    
int main()
{
    Solution s;
    int rows;
    cout<<"Input rows:";
    cin>>rows;
    for(auto x:s.pascal_triangle1(rows))
    {
        for(auto y:x)
        {
            cout<<y<<"  ";
        }
        cout<<endl;
    }
    cout<<"--------------------"<<endl;
    for(auto k:s.pascal_triangle2(rows))
    {
        cout<<k<<' ';
    }
    cout<<endl;
    return 0;
}
