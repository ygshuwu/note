#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;

pair<double,double> linear_regression(vector<double> &x,vector<double> &y)
{
    int x_size=x.size(),y_size=y.size();
    assert(x_size==y_size);
    double e_x=0.0,e_y=0.0,e_xy=0.0,e_xx=0.0;
    for(int i=0;i<x_size;i++)
    {
        e_x+=x[i];
        e_y+=y[i];
        e_xy+=x[i]*y[i];
        e_xx+=x[i]*x[i];
    }
    e_x/=x_size;
    e_y/=x_size;
    e_xy/=x_size;
    e_xx/=x_size;
    double cov_xy=e_xy-e_x*e_y;
    double var_x=e_xx-e_x*e_x;
    //the first repressent the k,the second repressent b
    pair<double,double> result;
    result.first=cov_xy/var_x;
    result.second=e_y-e_x*cov_xy/var_x;
    return result;
}

int main()
{
    vector<double> x={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0},y={1.91,4.21,6.23,7.90,10.07,12.12,14.15,16.90,17.90,20.08};
    pair<double,double> r=linear_regression(x,y);
    cout<<r.first<<"---------"<<r.second<<endl;
    return 0;
}
