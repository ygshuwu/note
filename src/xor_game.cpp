//leetcode:810
#include <iostream>
#include <vector>
#define N 1500
using namespace std;

vector<bool> tag(N,false);

bool xor_game(vector<int> &num)
{
	//1.female first.
	//2.assume the initial x=0 and the start is for(int &a:num){x^=a}
	//3.if x==0,then female will failed,if x!=0 female always could find two different number and delete one of them because x!=0 could result all elemet is no equal
	//4.if x!=0 and num.size()%2!=0.if female delete one number result x=0,then female will failed,if delete one number result x!=0,then male can use stratage 2 it courlf result female failed.
    int x=0;
	for(int &a:num)  x^=a;
	return x==0||num.size()%2==0;
}

int main()
{
	vector<int> list={3,4,56,4,6,8,7,2,1,3,5,45};
	cout<<boolalpha<<xor_game(list)<<endl;
	return 0;
}
