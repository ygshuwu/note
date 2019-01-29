#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

class BitMap
{
    public:
        vector<unsigned int> bitmap;
    public:
        void init_01(vector<unsigned int> &t,unsigned int maxnum);
        void init_02(vector<unsigned int> &t,unsigned int maxnum);
        void print(vector<unsigned int> &result);
    public:
        vector<unsigned int> bitmap_sort();
        vector<unsigned int> create_set_01();
        vector<unsigned int> create_set_02();
        bool has_number(unsigned int num);
};
void BitMap::init_01(vector<unsigned int> &t,unsigned int maxnum)
{
    //could be used for sort and create set,but we can distinct that whick number is dumplicated int int t[size].
    unsigned int N=maxnum/32U+1U;
    for(unsigned int i=0;i<N;i++)  bitmap.push_back(0U);
    int size=t.size();
    for(int j=0;j<size;j++)  bitmap[t[j]/32U]|=(1U<<t[j]%32U);
}
void BitMap::init_02(vector<unsigned int> &t,unsigned int maxnum)
{
    //only used for create set,00 means that the number is not in the t[size],01 means that the number int the t[size] is unique,10 means that the number in the t[size] is dumplicated.
    unsigned int N=maxnum/16U+1U;
    for(unsigned int i=0;i<N;i++)  bitmap.push_back(0U);
    int size=t.size();
    for(int j=0;j<size;j++)
    {
        if(!(bitmap[t[j]/16U]&(1U<<t[j]%16U*2U+1U)))
        {
            if(!(bitmap[t[j]/16U]&(1U<<t[j]%16*2U)))  bitmap[t[j]/16U]|=(1<<t[j]%16U*2U);
            else
            {
                bitmap[t[j]/16U]|=(1U<<t[j]%16U*2U+1U);
                unsigned int temp=UINT_MAX-(1U<<t[j]&16U*2U);
                bitmap[t[j]/16U]&=temp;
            }
        }
    }
}
vector<unsigned int> BitMap::bitmap_sort()
{
    //we must make sure that the number int the t[size] is unique.
    int size=bitmap.size();
    vector<unsigned int> result;
    for(int i=0;i<size;i++)
    {
        for(unsigned int k=0;k<32;k++)
        {
            if(bitmap[i]&(1U<<k))  result.push_back(i*32+k);
        }
    }
    return result;
}
vector<unsigned int> BitMap::create_set_01()
{
    return bitmap_sort();
}
vector<unsigned int> BitMap::create_set_02()
{
    //only used for that some number in the t[size] is dumplicated.
    vector<unsigned int> result;
    int size=bitmap.size();
    for(int i=0;i<size;i++)
    {
        for(unsigned int k=0;k<16U;k++)
        {
            if(bitmap[i]&(1U<<k*2U+1U))  result.push_back(i*16+k);
        }
    }
    return result;
}
bool BitMap::has_number(unsigned int num)
{
    return bitmap[num/32U]&(1U<<num%32U)?true:false;
}
void BitMap::print(vector<unsigned int> &result)
{
    for(auto &x:result)  cout<<x<<' ';
    cout<<endl;
}

int main()
{
    srand(time(0));
    vector<unsigned int> t(1000000,0U);
    for(int i=0;i<1000000;i++)  t[i]=static_cast<unsigned int>(rand()%10000);
    BitMap s;
    s.init_02(t,9999U);
    //vector<unsigned int> result=s.bitmap_sort();
    vector<unsigned int> result=s.create_set_02(); 
    s.print(result);
    cout<<boolalpha<<s.has_number(3546U)<<endl;
    return 0;
}
