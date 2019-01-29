#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> subset(vector<int> &s);
    private:
        static void subset(const vector<int> &s,vector<int> &path,int step,vector<vector<int>> &result)
        {
            if(step==s.size())
            {
                result.push_back(path);
                return;
            }
            //don't select s[step]
            subset(s,path,step+1,result);
            //select s[step]
            path.push_back(s[step]);
            subset(s,path,step+1,result);
            path.pop_back();
        }
};
vector<vector<int>> Solution::subset(vector<int> &s)
{
    //time complity O(2^n)
    //sapce complexity O(n)
    sort(s.begin(),s.end());
    vector<vector<int>> result;
    vector<int> path;
    subset(s,path,0,result);
    return result;
}
int main()
{
    vector<int> test={1,2,3,4,5,6};
    Solution s;
    for(auto x:s.subset(test))
    {
        if(x.size()!=0)
        {
            for(auto y:x)
            {
                cout<<y<<' ';
            }
            cout<<endl;
        }
        else  cout<<"null"<<endl;
    }
    return 0;
}
