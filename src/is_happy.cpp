//leetcode:202
#include <iostream>
using namespace std;

int f(int n)
{
	int temp=0;
	while(n!=0)
	{
		temp+=n%10;
		n/=10;
	}
	return temp;
}
bool is_happy(int n)
{
	while(true)
	{
		int temp=n;
		n=f(n);
		if(n==1)  return true;
		if(temp==n)  return false;
	}

}

int main()
{
	int x;
	cout<<"Input the number:";
	cin>>x;
	cout<<boolalpha<<is_happy(x)<<endl;
	return 0;
}
