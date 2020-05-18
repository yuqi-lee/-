#include<iostream>
using namespace std;

double a,b,c,d;

double _function(double x);
double _result(double x, double y);

int main(void){
    cin>>a>>b>>c>>d;
    double result[3];
    int count = 0;
    for(double x = -100 ; x <= 100 && count < 3 ;x += 0.9)
    {
        if(_function(x) * _function(x+0.9) < 0)
        {
            result[count] = _result(x,x+0.9);
            count++;
        }
    }
    printf("%.2lf %.2lf %.2lf\n",result[0],result[1],result[2]);
}

double _function(double x){
    return(a*x*x*x + b*x*x + c*x + d);
}

double _result(double x, double y){

    for(;y - x >= 1e-6 ;)
    {
        double z = (x+y)/2;
        (_function(x)*_function(z)) >= 0 ? x = z : y = z;
    }
    return x;
}