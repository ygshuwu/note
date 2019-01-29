#include <iostream>
using namespace std;

int reverse_interger(int x)
{
    //must consider overflow,example x=-2147483648
    long long r=0,t=x;
    t>0?t:-t;
    //core code
    for(;t;t/=10)
    {
        r=r*10+t%10;
    }
    bool sign=x>0?true:false;
    if(r>2147483467||(sign&&r>2147483468))  return 0;
    else  return sign?r:-r;
}

int main()
{
    int x,result;
    cout<<"Input the number:";
    cin>>x;
    result=reverse_interger(x);
    cout<<"The result is:"<<result<<endl;
    return 0;
}    
