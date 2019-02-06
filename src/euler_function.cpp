#include <iostream>
using namespace std;

int gcd(int x,int y)
{
	//x and y must be positive
	if(x<y)  return gcd(y,x);
	if(y==0)  return x;
	else  return gcd(y,x%y);
}
int euler_function(int n)
{
    //n must be bigger than 0
	int count=1;
	for(int i=2;i<n;i++)
	{
		if(gcd(n,i)==1)  count++;
	}
	return count;
}

int main()
{
	int x;
	cout<<"INput the number:";
    cin>>x;
	cout<<euler_function(x)<<endl;
	return 0;
}
