#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> threesum1(vector<int> &num,int target);
        vector<vector<int>> threesum2(vector<int> &num,int target);
};
vector<vector<int>> Solution::threesum1(vector<int> &num,int target)
{
    //time complexity O(n^2)
    //space complexity O(1)
    vector<vector<int>> result;
    vector<int> q;
    sort(num.begin(),num.end());
    for(int i=0;i<num.size()-2;i++)
    {
        if(i>0&&num[i]==num[i-1])
        {
            continue;
        }
        int j=i+1,k=num.size()-1;
        while(j<k)
        {
            if(num[i]+num[j]+num[k]<target)
            {
                j++;
                while(num[j]==num[j-1]&&j<k)
                {
                    j++;
                }
            }
            else if(num[i]+num[j]+num[k]>target)
            {
                k--;
                while(num[k]==num[k+1]&&j<k)
                {
                    k--;
                }
            }
            else
            {
                q.clear();
                q.push_back(i);
                q.push_back(j);
                q.push_back(k);
                result.push_back(q);
                j++;
                k--;
                while(num[j]==num[j-1]&&num[k]==num[k-1]&&j<k)
                {
                    j++;
                }
            }
        }
    }
    if(result.size()==0)
    {
        q.clear();
        q.push_back(-1);
        q.push_back(-1);
        q.push_back(-1);
        result.push_back(q);
    }
    return result;
}
vector<vector<int>> Solution::threesum2(vector<int> &num,int target)
{
    //time complexity O(n^3)
    //space complexity O(1)
    vector<vector<int>> result;
    vector<int> q;
    for(int i=0;i<num.size()-2;i++)
    {
        for(int j=i+1;i<num.size()-1;j++)
        {
            for(int k=j+1;k<num.size();k++)
            {
                if(num[i]+num[j]+num[k]==target)
                {
                    q.clear();
                    q.push_back(i);
                    q.push_back(j);
                    q.push_back(k);
                    result.push_back(q);
                }
            }
        }
    }
    if(result.size()==0)
    {
        q.clear();
        q.push_back(-1);
        q.push_back(-1);
        q.push_back(-1);
        result.push_back(q);
    }
    return result;
}

int main()
{
    vector<int> array={1,2,3,4,5,6,7,8,9,10,11,12};
    Solution s;
    vector<vector<int>> p;
    int target;
    cout<<"Input the target:";
    cin>>target;
    p=s.threesum1(array,target);
    for(auto x:p)
    {
        for(auto y:x)
        {
            cout<<y<<' ';
        }
        cout<<endl;
    }
    return 0;
} 
