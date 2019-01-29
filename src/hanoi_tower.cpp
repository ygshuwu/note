#include <iostream>
using namespace std;

void move(int n,char a,char b,char c)
{
	if(n==1)  cout<<"put "<<n<<"th item from "<<a<<" to "<<c<<" use "<<b<<endl;
	else
	{
		move(n-1,a,c,b);
		cout<<"put "<<n<<"th item from "<<a<<" to "<<b<<" use "<<c<<endl;
		move(n-1,b,a,c);
	}
}

int main()
{
	int num;
	cout<<"Input the hanoi tower hight:";
	cin>>num;
	move(num,'a','b','c');
	return 0;
}
