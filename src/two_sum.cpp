#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> twosum1(vector<int> &num,int target);
        vector<vector<int>> twosum2(vector<int> &num,int target);
        vector<vector<int>> twosum3(vector<int> &num,int target);
};
vector<vector<int>> Solution::twosum1(vector<int> &num,int target)
{
    //time complexity O(n^2)
    //space complexity O(1)
    vector<vector<int>> result;
    vector<int> q;
    for(int i=0;i<num.size()-1;i++)
    {
        for(int j=i+1;j<num.size();j++)
        {
            if(num[i]+num[j]==target)
            {
                q.clear();
                q.push_back(i+1);
                q.push_back(j+1);
                result.push_back(q);
            }
        }
    }
    if(result.size()==0)
    {
        q.clear();
        q.push_back(-1);
        q.push_back(-1);
        result.push_back(q);
    }
    return result;
}
vector<vector<int>> Solution::twosum2(vector<int> &num,int target)
{
    //time complexity O(n)
    //space complexity O(n)
    unordered_map<int,int> mapping;
    vector<vector<int>> result;
    vector<int> q;
    int gap;
    for(int i=0;i<num.size();i++)
    {
        mapping[num[i]]=i;
    }
    for(int j=0;j<num.size();j++)
    {
        gap=target-num[j];
        if(mapping.find(gap)!=mapping.end()&&mapping[gap]>j)
        {
            q.clear();
            q.push_back(j+1);
            q.push_back(mapping[gap]+1);
            result.push_back(q);
        }
    }
    if(result.size()==0)
    {
        q.clear();
        q.push_back(-1);
        q.push_back(-1);
        result.push_back(q);
    }
    return result;
}   
vector<vector<int>> Solution::twosum3(vector<int> &num,int target)
{
    //time complexity O(n)
    //space complexity O(1)
    vector<vector<int>> result;
    vector<int> q;
    sort(num.begin(),num.end());
    int i=0,j=num.size()-1;
    while(i<j)
    {
        if(num[i]+num[j]<target)
        {
            i++;
        }
        else if(num[i]+num[j]>target)
        {
            j--;
        }
        else
        {
            q.clear();
            q.push_back(i+1);
            q.push_back(j+1);
            result.push_back(q);
        }
    }
    if(result.size()==0)
    {
        q.clear();
        q.push_back(-1);
        q.push_back(-1);
        result.push_back(q);
    }
    return result;
}

int main()
{
    vector<int> array={1,2,3,4,5,6,7,8,9,10,11};
    vector<vector<int>> p;
    Solution s;
    int target;
    cout<<"Input the target:";
    cin>>target;
    p=s.twosum1(array,target);
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
