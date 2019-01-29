#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> foursum(vector<int> &num,int &target);
};
vector<vector<int>> Solution::foursum(vector<int> &num,int &target)
{
    //time complexity O(n^3)
    //space complexity O(1)
    //k-sum question----->time complexity max(nlogn,n^(k-1))
    vector<vector<int>> p;
    vector<int> q;
    int n=num.size();
    sort(num.begin(),num.end());
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int k=j+1,l=n-1;
            while(k<l)
            {
                if(num[i]+num[j]+num[k]+num[l]<target)
                {
                    k++;
                }
                else if(num[i]+num[j]+num[k]+num[l]>target)
                {
                    l--;
                }
                else
                {
                    q.clear();
                    q.push_back(i);
                    q.push_back(j);
                    q.push_back(k);
                    q.push_back(l);
                    p.push_back(q);
                }
           }
        }
    }
    if(p.size()==0)
    {
        q.clear();
        for(int f=0;f<4;f++)
        {
            q.push_back(-1);
        }
        p.push_back(q);
    }
    return p;
}

int main()
{
    vector<int> array={1,2,3,4,5};
    Solution s;
    vector<vector<int>> result;
    int target;
    cout<<"Input the target:";
    cin>>target;
    result=s.foursum(array,target);
    for(auto x:result)
    {
        for(auto y:x)
        {
            cout<<y<<' ';
        }
        cout<<endl;
    }
    return 0;
}
