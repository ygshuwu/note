#include <iostream>
using namespace std;

class UF1
{
	//union find set
	private:
		int count;
		int *id;
	public:
		UF1(int n);
		~UF1();
		int size();
		bool is_connect(int a,int b);
        int find(int a);
		void merge(int a,int b);
};
class UF2
{
	private:
		int count;
		int *id;
	public:
		UF2(int n);
		~UF2();
		int size();
		bool is_connect(int a,int b);
		int find(int a);
		void merge(int a,int b);
};
class UF3
{
	private:
		int count;
		int *id;
		int *sz;
	public:
		UF3(int n);
		~UF3();
        int size();
		bool is_connect(int a,int b);
		int find(int a);
		void merge(int a,int b);
};
UF1::UF1(int n)
{
	count=n;
	id=new int[n];
	for(int i=0;i<n;i++)  id[i]=i;
}
UF1::~UF1()
{
	delete []id;
	//delete id is also could sucess for simple type
}
int UF1::size()
{
	return count;
}
bool UF1::is_connect(int a,int b)
{
	return find(a)==find(b);
}
int UF1::find(int a)
{
	if(a>=0&&a<count)  return id[a];
	return -1;
}
void UF1::merge(int a,int b)
{
	int pa=find(a),pb=find(b);
	if(pa==pb)  return;
	for(int i=0;i<count;i++)
	{
		if(id[i]==pa)  id[i]=pb;
	}
	count--;
}
UF2::UF2(int n)
{
	count=n;
	id=new int[n];
	for(int i=0;i<count;i++)  id[i]=i;
}
UF2::~UF2()
{
	delete []id;
}
int UF2::size()
{
	return count;
}
bool UF2::is_connect(int a,int b)
{
	return find(a)==find(b);
}
int UF2::find(int a)
{
	while(id[a]!=a)  a=id[a];
	return a;
}
void UF2::merge(int a,int b)
{
	int pa=find(a),pb=find(b);
	if(pa==pb)  return;
	id[pa]=pb;
	count--;
}
UF3::UF3(int n)
{
	count=n;
	id=new int[n];
	sz=new int[n];
	for(int i=0;i<count;i++)  id[i]=i;
	for(int i=0;i<count;i++)  sz[i]=1;
}
UF3::~UF3()
{
	delete []id;
	delete []sz;
}
int UF3::size()
{
	return count;
}
bool UF3::is_connect(int a,int b)
{
	return find(a)==find(b);
}
int UF3::find(int a)
{
    while(id[a]!=a)  a=id[a];
	return a;
}
void UF3::merge(int a,int b)
{
	int pa=find(a),pb=find(b);
	if(pa==pb)  return;
	if(sz[pa]<sz[pb])
	{
		id[pa]=pb;
		sz[pb]+=sz[pa];
	}
	else
	{
		id[pb]=pa;
		sz[pa]+=sz[pb];
	}
	count--;
}

int main()
{
	UF3 f(10);
	cout<<boolalpha<<f.is_connect(1,4)<<endl;
	f.merge(1,4);
	cout<<boolalpha<<f.is_connect(1,4)<<endl;
	return 0;
}
