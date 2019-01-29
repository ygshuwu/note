#include <iostream>
#include <vector>
using namespace std;

bool is_odd(int x)
{
	return x&1;
}
bool is_even(int x)
{
	return !(x&1);
}
bool is_power_of_two(int x)
{
	return !(x&(x-1));
}
int single_number(vector<int> &list)
{
	//leetcode:136
	//time complexity:O(n)
	//space complexity:O(1)
	int result=0;
	for(auto &i:list)  result^=i;
	return result;
}
int single_number_II(vector<int> &list)
{
    //leetcode:137
	//time complexity:O(n)
	//space complexity:O(1)
	int low=0,high=0,len=list.size();
	for(int i=0;i<len;i++)
	{
		low=(low^list[i])&(~high);
		high=(high^list[i])&(~low);
	}
	return low;
}
vector<int> single_number_III(vector<int> &list)
{
    //time complexity:O(2*n)--O(n)
	//space complexity:O(1)
    vector<int> s;
	int result=0,index=-1,size=list.size();
	for(auto &temp:list)  result^=temp;
	for(int i=0;i<32;i++)
	{
		if(result&(1<<i))
		{
			index=i;
			break;
		}
	}
	int temp=0;
	for(int k=0;k<size;k++)
	{
		if(list[k]&(1<<index))  temp^=list[k];
	}
	result^=temp;
	s.push_back(temp);
	s.push_back(result);
	return s;
}
int count_bits(int x)
{
	int result=0;
	if(x<0)
	{
		result++;
		x=-x;
	}
	while(x)
	{
		x=x&(x-1);
		result++;
	}
	return result;
}
void swap(int &x,int &y)
{
	x=x^y;
	y=x^y;
	x=x^y;
}
int add(int x,int y)
{
    int temp;
	while(x)
    {
	    temp=x;
		x=temp^y;
		y=(temp&y)<<1;
	}
	return y;
}
vector<vector<int>> subsets(vector<int> &list)
{
	const int size=list.size(),N=1<<(size-1);
	vector<vector<int>> result(N,vector<int>());
	for(int i=0;i<N;i++)
	{
		for(int k=0;k<size;k++)
		{
			if(i&(1<<k))  result[i].push_back(list[k]);
		}
	}
	return result;
}
void print(vector<int> &list)
{
	for(auto &i:list)  cout<<i<<' ';
	cout<<endl;
}

int main()
{
    vector<int> t1={2,3,3,4,5,6,5,6,4};
	vector<int> t2={2,3,6,5,5,6,7,8,7,9,9,8};
	vector<int> t3={1,3,4,5,4,3,5,5,3,4},s;
	cout<<single_number(t1)<<endl;
	cout<<single_number_II(t3)<<endl;
	s=single_number_III(t2);
	print(s);
	return 0;
}
