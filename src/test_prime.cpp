#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<unsigned long> generate_mersenne_number()
{
	vector<unsigned long> s;
	unsigned long t=0UL;
	for(int i=0;i<63;i++)
	{
		t=(t<<1)+1UL;
	 	s.push_back(t);
	}
	return s;
}
void lucas_lehmer_test(vector<unsigned long> &list)
{
    //only used test mersenne number and p must be prime,or Mp is not a prime
	vector<int> p={2,3,5,7,11,13,17,19,23,29,31};
	cout<<list[p[0]-1]<<"------"<<boolalpha<<true<<endl;
	for(int i=1;i<p.size();i++)
	{
		unsigned long t=4UL;
		for(int u=1;u<=p[i]-2;u++)  t=(t*t-2UL)%list[p[i]-1];
		cout<<list[p[i]-1]<<"------";
		if(t%list[p[i]-1]==0)  cout<<boolalpha<<true<<endl;
		else  cout<<boolalpha<<false<<endl;
	}
}
void print(vector<unsigned long> &list)
{
	for(auto &temp:list)  cout<<temp<<' ';
	cout<<endl;
}

int main()
{
	vector<unsigned long> list=generate_mersenne_number();
	//print(list);
	lucas_lehmer_test(list);
	return 0;
}
