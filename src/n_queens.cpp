#include <iostream>
#include <vector>
#include <string>
#define M 10
using namespace std;

class Solution
{
    public:
        int count;
	vector<vector<string>> result;
    public:
        void solve_n_queens(int n);
	void print(const vector<vector<string>> &result);
    private:
        bool isvalid(const vector<int> &C,int row,int col);
	void dfs(vector<int> &C,vector<vector<string>> &result,int row);
	void dfs_only_count(vector<int> &C,int row);
};
bool Solution::isvalid(const vector<int> &C,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if(C[i]==col)  return false;
	if(abs(i-row)==abs(C[i]-col))  return false;
    }
    return true;
}
void Solution::print(const vector<vector<string>> &result)
{
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<M;j++)
	{
            for(int k=0;k<M;k++)
	    {
	        cout<<result[i][j][k]<<' ';
	    }
	    cout<<endl;
	}
	cout<<"****************************************************"<<endl;
    }
}    
void Solution::dfs(vector<int> &C,vector<vector<string>> &result,int row)
{
    const int N=C.size();
    if(row==N)
    {
        vector<string> solution;
	for(int i=0;i<N;i++)
	{
	    string s(N,'.');
	    for(int j=0;j<N;j++)
	    {
	        if(j==C[i])  s[j]='Q';
	    }
	    solution.push_back(s);
        }
	result.push_back(solution);
	count++;
        return;
    }
    for(int k=0;k<N;k++)
    {
        const bool t=isvalid(C,row,k);
	if(!t)  continue;
	C[row]=k;
	dfs(C,result,row+1);
    }
}
void Solution::dfs_only_count(vector<int> &C,int row)
{
    const int N=C.size();
    if(row==N)
    {
        count++;
	return;
    }
    for(int k=0;k<N;k++)
    {
        const bool t=isvalid(C,row,k);
	if(!t)  continue;
	C[row]=k;
	dfs_only_count(C,row+1);
    }
}
void Solution::solve_n_queens(int n)
{
    vector<int> C(n,-1);
    dfs(C,result,0);
}

int main()
{
    Solution s;
    s.count=0;
    s.solve_n_queens(M);
    s.print(s.result);
    cout<<s.count<<endl;
    return 0;
}
