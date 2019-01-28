#include <iostream>
using namespace std;

bool is_odd(int x)
{
	return x&1;
}
bool is_even(int x)
{
	return !(x&1);
}

int main()
{
    int x;
	cout<<"Input te number:";
	cin>>x;
	cout<<boolalpha<<is_odd(x)<<endl;
	//cout<<boolalpha<<is_enve(x)<<endl;
	return 0;
}
