#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> trial_division_01(int n)
{
	vector<int> result;
	for(int i=2;i<=n;i++)
	{
		bool flag=true;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)  result.push_back(i);
	}
	return result;
}
vector<int> trial_division_02(int n)
{
	vector<int> result;
	for(int i=2;i<=n;i++)
	{
		bool flag=true;
		for(int j=2;j<=(i>>1);j++)
		{
			if(i%j==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)  result.push_back(i);
	}
	return result;
}
vector<int> trial_division_03(int n)
{
	vector<int> result;
	for(int i=2;i<=n;i++)
	{
		bool flag=true;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)  result.push_back(i);
	}
	return result;
}
vector<int> trial_division_04(int n)
{
    //time complexity:O(n*sqrt(n)/log(n)^2)
	//space complexity:in fact--O(n/log(n)),in theory--O(n)
	//for optimization,the prime bigger than sqrt(n) could not be stroed,space complexity:in fact--O(sqrt(n)/log(sqrt(n))),in theory--O(sqrt(n))
	int num_prime=0;
	vector<int> result;
	for(int i=2;i<=n;i++)
	{
		bool flag=true;
        for(int j=0;j<num_prime;j++)
		{
		    int p=result[j];
			if(p*p>i)  break;
			if(i%p==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			num_prime++;
			result.push_back(i);
		}
	}
	return result;
}
vector<int> sieve_of_eratosthenes(int n)
{
    //time complexity:O(n*log(log(n)))---->n/2+n/3+n/5+...=O(n*log(log(n)))
	//space complexity:in fact and in theory--O(n)
	vector<int> list(n+1,0);
	vector<int> result;
	//intialize list
	for(int i=2;i<=n;i++)  list[i]=i;
	//core code
	for(int k=2;k*k<=n;k++)
	{
	    if(list[k])
		{
			for(int x=k*k;x<=n;x+=k)  list[x]=0;
		}
	}
	for(int l=2;l<=n;l++)
	{
		if(list[l])  result.push_back(list[l]);
	}
	return result;
}
vector<int> sieve_of_euler_01(int n)
{
    //time complexity:O(n)
	//sapce complexity:in fact--O(n),in theory--O(n*log(n))
	vector<int> prev(n+2,0),next(n+2,0),result;
	for(int i=2;i<=n;i++)
	{
		prev[i]=i-1;
		next[i]=i+1;
	}
	for(int p=2;p*p<=n;p=next[p])
	{
		for(int f=p;p*f<=n;f=next[f])
		{
			for(int x=p*f;;x*=p)
			{
				next[prev[x]]=next[x];
				prev[next[x]]=prev[x];
				if(x>n/p)  break;
			}
		}
	}
    for(int k=2;k<=n;k=next[k])  result.push_back(k);
	return result;
}
vector<int> sieve_of_euler_02(int n)
{
    //time complexity:O(n)
	//sapce complexity:in fact--O(n),in theory--O(n*log(n))
	vector<int> prev(n+2,0),next(n+2,0),result;
    for(int i=2;i<=n;i++)
	{
		prev[i]=i-1;
		next[i]=i+1;
	}
	for(int p=2;p*p<=n;p=next[p])
	{
		int f=p;
		while(p*next[f]<=n)  f=next[f];
        while(f>=p)
		{
			int x=p*f;
			next[prev[x]]=next[x];
			prev[next[x]]=prev[x];
			f=prev[f];
		}
	}
	for(int k=2;k<=n;k=next[k])  result.push_back(k);
	return result;
}
vector<int> simple_euler(int n)
{
	//time complexity:O(n)
	//space complexity:
	//for flag vector:in fact and in theory--O(n)
	//for result vector:in fact--O(sqrt(n)/log(sqrt(n)),in theory--O(sqrt(n))
    int num_prime=0;
	vector<bool> flag(n+1,true);
	vector<int> result;
	for(int f=2;f<=n/2;f++)
	{
		if(flag[f])
		{
			num_prime++;
			result.push_back(f);
		}
		for(int u=0;u<num_prime;u++)
		{
			int p=result[u];
			if(p*f>n)  break;
			flag[p*f]=false;
			if(f%p==0)  break;
		}
	}
	for(int k=n/2+1;k<=n;k++)
	{
		if(flag[k])  result.push_back(k);
	}
	return result;
}
vector<int> bengalloun(int n)
{
    //time complexity:O(n)
	//sapce complexity:
	//flag vector:in fact and in theory--O(n)
	//lpfindex vector:in fact--O(n),in theory--O(n*log(n))
	//result vector:in fact--O(n/log(n)),in theory--O(n)
	//sum of flag,lpfindex,result:in fact--O(n),in theory--O(n*log(n))
	vector<bool> flag(2*n+1,true);
	vector<int> lpfindex(2*n+1,0),result;
	//flag[2]=true;
	for(int i=2;i<=n;i++)
	{
        //flag[i*2-1]=true;
		flag[i*2]=false;
		//lpfindex[2*i]=0;
		if(flag[i])  result.push_back(i);
		else
		{
			int u=lpfindex[i];
			int p=result[u];
			int f=i/p;
			if(f%p!=0)
			{
				int j=result[u+1]*f;
				flag[j]=false;
				lpfindex[j]=u+1;
			}
		}
	}
	return  result;
}
vector<int> segmented_eratosthenes(int n)
{
    //time complexity:O(n*log(log(n)))
    //space complexity:in fact--O(sqrt(n)),in theory--O(sqrt(n))
	//in practice,it is faster than sieve of eratosthenes due to flag vector could be stroed in cached
    vector<bool> flag;
	vector<int> result;
    int sqrt_n=static_cast<int>(sqrt(static_cast<double>(n)));
	result=sieve_of_eratosthenes(sqrt_n);
	int size=result.size();
	int len=sqrt_n;
	for(int start=sqrt_n+1;start<=n;start+=len)
	{
		if(start+len>n)  len=n-start+1;
		flag.assign(len,true);
		for(int u=0;u<size;u++)
		{
			int p=result[u];
			if(p*p>=start+len)  break;
			for(int i=(p-start%p)%p;i<len;i+=p)  flag[i]=false;
		}
		for(int k=0;k<len;k++)
		{
			if(flag[k])  result.push_back(start+k);
		}
	}
	return result;
}
void print(vector<int> &list)
{
	for(auto &tmp:list)  cout<<tmp<<' ';
	cout<<endl;
}
void build_wheel(int max_wheel_len,vector<int> &result,int &wheel_len,int &wheel_order,int &wheel_count)
{
    //initialize
    result.clear();
	result.push_back(2);
	wheel_len=2;
	wheel_order=1;
	//for caculate wheel_order,wheel_len,wheel_count
	for(int i=3;wheel_len<=max_wheel_len/i;i++)
	{
		bool tag=true;
		for(int u=0;u<wheel_order;u++)
		{
			if(i%result[u]==0)
			{
				tag=false;
				break;
			}
		}
		if(tag)
		{
			wheel_order++;
			wheel_len*=i;
			result.push_back(i);
		}
	}
}
void generate_gap_and_id(vector<bool> &flag,vector<int> &result,vector<int> &gap,vector<int> &id,const int &wheel_len,const int &wheel_order,int &wheel_count)
{
	//initialize flag
	flag.clear();
	flag.assign(wheel_len,true);
	//generate flag 
	for(int u=0;u<wheel_order;u++)
	{
		for(int i=result[u];i<=wheel_len;i+=result[u])  flag[i-1]=false;
	}
    //intialize gap and id
	gap.clear();
	id.clear();
	gap.assign(wheel_len,-1);
	id.assign(wheel_len,-1);
    gap[wheel_len-2]=2;
	id[0]=0;
    //generate gap and id
	int t=1;
	for(int i=2;i<=wheel_len;i++)
	{
		if(flag[i-1])
		{
			gap[t-1]=i-t;
			id[i-1]=id[t-1]+1;
			t=i;
		}
	}
	//print(gap);
	//print(id);
	wheel_count=id[wheel_len-2]+1;
	//cout<<wheel_count<<endl;
}
int roll_wheel(int x,vector<int> &gap,int wheel_len)
{
	return x+gap[x%wheel_len-1];
}
int wheel_index(int x,int wheel_len,int wheel_count,vector<int> &id)
{
	return x/wheel_len*wheel_count+id[x%wheel_len-1];
}
vector<int> wheel_eratosthenes(int n)
{
    //time complexity:O(n)--faster than sieve of eratosthenes
	//space complexity:in fact and in theory--O(n/log(log(n)))
    int max_wheel_len=static_cast<int>(sqrt(static_cast<double>(n)));
    int wheel_len,wheel_order,wheel_count;
	vector<bool> flag;
	vector<int> gap,id,result;
	build_wheel(max_wheel_len,result,wheel_len,wheel_order,wheel_count);
	generate_gap_and_id(flag,result,gap,id,wheel_len,wheel_order,wheel_count);
    int flag_size=(n/wheel_len+1)*wheel_count;
	flag.assign(flag_size,true);
	int pmin=gap[0]+1;
	int p=pmin,p_index=1;
	while(p*p<=n)
	{
		if(flag[p_index])
		{
			for(int f=p;p*f<=n;f=roll_wheel(f,gap,wheel_len))  flag[wheel_index(p*f,wheel_len,wheel_count,id)]=false;
		}
        p=roll_wheel(p,gap,wheel_len);
		p_index++;
	}
	int i=pmin,i_index=1;
	while(i<=n)
	{
		if(flag[i_index])  result.push_back(i);
		i=roll_wheel(i,gap,wheel_len);
		i_index++;
	}
	return result;
}
vector<int> wheel_simple_euler(int n)
{
	//time complexity:O(n/log(log(n))--faster than O(n)--simple euler:O(n)
	//space complexity:in fact and in theory--O(n/log(log(n))
    int max_wheel_len=static_cast<int>(sqrt(static_cast<double>(n)));
	int wheel_len,wheel_order,wheel_count;
	vector<bool> flag;
	vector<int> result,gap,id;
    build_wheel(max_wheel_len,result,wheel_len,wheel_order,wheel_count);
	generate_gap_and_id(flag,result,gap,id,wheel_len,wheel_order,wheel_count);
	int flag_size=(n/wheel_len+1)*wheel_count;
    flag.assign(flag_size,true);
	int pmin=gap[0]+1;
	int f=pmin,f_index=1;
	while(pmin*f<=n)
	{
		if(flag[f_index])  result.push_back(f);
		int num_primes=result.size();
		for(int u=wheel_order;u<num_primes;u++)
		{
			int p=result[u];
			if(p*f>n)  break;
			flag[wheel_index(p*f,wheel_len,wheel_count,id)]=false;
			if(f%p==0)  break;
		}
		f=roll_wheel(f,gap,wheel_len);
		f_index++;
	}
	while(f<=n)
	{
		if(flag[f_index])  result.push_back(f);
		f=roll_wheel(f,gap,wheel_len);
		f_index++;
	}
	return result;
}
vector<int> wheel_segmented_eratosthenes(int n)
{
    //time complexity:O(n)
	//space complexity:in fact and in theory--O(sqrt(n)/log(log(n)))
    int wheel_len,wheel_order,wheel_count;
	vector<bool> flag;
	vector<int> result,gap,id;
	int max_wheel_len=static_cast<int>(sqrt(static_cast<double>(n)));
	build_wheel(max_wheel_len,result,wheel_len,wheel_order,wheel_count);
	generate_gap_and_id(flag,result,gap,id,wheel_len,wheel_order,wheel_count);
	
	result=sieve_of_eratosthenes(max_wheel_len);
	vector<int> factors=result;
	int num_primes=result.size();

	int segstart=1;
	while(segstart<=max_wheel_len)  segstart=roll_wheel(segstart,gap,wheel_len);
	int seglen=max_wheel_len;
	while(segstart<=n)
	{
		int segend=segstart+seglen-1;
		if(segend>n)  segend=n;
		flag.assign(seglen,true);
		for(int u=wheel_order;u<num_primes;u++)
		{
			int p=result[u],f=factors[u];
			while(f*p<=segend)
			{
				flag[p*f-segstart]=false;
				f=roll_wheel(f,gap,wheel_len);
			}
			factors[u]=f;
		}
		int i;
		for(i=segstart;i<=segend;i=roll_wheel(i,gap,wheel_len))
		{
			if(flag[i-segstart])  result.push_back(i);
		}
		segstart=i;
	}
	return result;
}
double prime_density(int n)
{
	int num_primes=wheel_eratosthenes(n).size();
	//int num_primes=wheel_segmented_eratosthenes(n).size();
	return static_cast<double>(num_primes)/n;
}
void list_prime_density()
{
	int start=100,end=100000000;
	while(start<=end)
	{
	    cout<<start<<"------";
		cout<<prime_density(start)<<endl;
		start*=10;
	}
}

int main()
{
	int x;
	cout<<"Input the number:";
	cin>>x;
	vector<int> result;
    //result=trial_division_01(x);
	//result=trial_division_02(x);
	//result=trial_division_03(x);
	//result=trial_division_04(x);
	//result=sieve_of_eratosthenes(x);
	//result=sieve_of_euler_01(x);
    //result=sieve_of_euler_02(x);
	//result=simple_euler(x);
	//result=bengalloun(x);
	//result=segmented_eratosthenes(x);
	//result=wheel_eratosthenes(x);
	//result=wheel_simple_euler(x);
	result=wheel_segmented_eratosthenes(x);
	//cout<<prime_density(x)<<endl;
	//list_prime_density();
	cout<<result.size()<<endl;
	print(result);
	return 0;
}
