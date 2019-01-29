#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

class Solution
{
    public:
        int threesum1_closest(vector<int> &num,int target);
        int threesum2_closest(vector<int> &num,int target);
        vector<vector<int>> threesum3_closest(vector<int> &num,int target);
};
int Solution::threesum1_closest(vector<int> &num,int target)
{
    //time complexity O(n^2)
    //space complexity O(1)
    int result=0,min_gap=INT_MAX;
    for(int i=0;i<num.size()-2;i++)
    {
        int j=i+1,k=num.size()-1;
        while(j<k)
        {
            const int sum=num[i]+num[j]+num[k];
            const int gap=abs(sum-target);
            if(gap<min_gap)
            {
                result=sum;
                min_gap=gap;
            }
            if(sum<target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return result;
}
int Solution::threesum2_closest(vector<int> &num,int target)
{
    //time complexity O(n^2)
    //space complexity O(1)
    //using prev function(from <iterator>),prev function returns the nth predecessor of iterator it
    //(prev(it,n))--->default n=1
    int result=0,min_gap=INT_MAX;
    sort(num.begin(),num.end());
    for(auto a=num.begin();a!=prev(num.end(),2);a++)
    {
        auto b=prev(a);
        auto c=prev(num.end());
        while(b<c)
        {
            const int sum=*a+*b+*c;
            const int gap=abs(sum-target);
            if(gap<min_gap)
            {
                result=sum;
                min_gap=gap;
            }
            if(sum<target)
            {
                b++;
            }
            else
            {
                c--;
            }
        }
    }
    return result;
}
vector<vector<int>> Solution::threesum3_closest(vector<int> &num,int target)
{
    //time comlexity O(n^2)
    //space complexity O(1)
    vector<vector<int>> p;
    vector<int> q;
    map<int,vector<int>> mapping;
    int result=0,min_gap=INT_MAX;
    sort(num.begin(),num.end());
    for(int i=0;i<num.size()-2;i++)
    {
        int j=i+1,k=num.size()-1;
        while(j<k)
        {
            const int sum=num[i]+num[j]+num[k];
            const int gap=abs(sum-target);
            if(gap<=min_gap)
            {
                q.clear();
                q.push_back(i+1);
                q.push_back(j+1);
                q.push_back(k+1);
                mapping[gap]=q;
                result=sum;
                min_gap=gap;
            }
            if(sum<target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    auto start=mapping.begin();
    for(auto it=mapping.begin();it!=mapping.end()&&it->first==start->first;it++)
    {
            p.push_back(it->second);
    }
    return p;
}

int main()
{
    vector<int> array={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<vector<int>> result_index;
    Solution s;
    int result,target;
    cout<<"Input the target:";
    cin>>target;
    result=s.threesum1_closest(array,target);
    cout<<"The result:"<<result<<endl;
    cout<<"---------------"<<endl;
    result_index=s.threesum3_closest(array,target);
    for(auto x:result_index)
    {
        for(auto y:x)
        {
            cout<<y<<' ';
        }
        cout<<endl;
    }
    return 0;
}
