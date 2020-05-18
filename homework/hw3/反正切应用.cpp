/*
    李昱祁  PB18071496  程序设计II第 3 次作业

    题目 2：反正切应用

                    2020.04.02
                                                */

#include<iostream>
using namespace std;


long my_func(long a,long& b,long &c);

int main()
{
    cout<<endl<<"=========================反正切函数的应用========================="<<endl<<endl;
    cout<<"计算满足 arctan(1/a) = arctan(1/b) + arctan(1/c) 的 b、c "<<endl<<endl;
    cout<<"请输入 a:";
    long a;
    cin>>a;
    long b = 0,c = 0;
    long sum = my_func(a,b,c);
    cout<<endl<<"结果为 b = "<<b<<"  c = "<<c<<endl<<endl;
    cout<<"       b + c = "<<sum<<endl;
    return 0;
}



long my_func(long a,long& b,long& c)
{
    /*
        首先必有解  b = a + 1, c = a^2 + a + 1
        以此解为初始解
        之后从初始解出发遍历确定最优解
                                           */
    long _b,_c;
    b = _b = a + 1;
    c = a*a + a + 1;
    long sum = b + c;
    for(_b = _b + 1 ; _b < sum ; _b++)      //若 b 已经 >= 已知最小的 sum，则遍历结束
    {
        if((_b*a + 1) % (_b - a) == 0)
        {
            _c = (_b*a + 1) / (_b - a);
            if(_c + _b < sum)   //若有和更小的解，则替换之
            {
                b = _b;
                c = _c;
                sum = b + c;
            }
        }
    }
    return(sum);
}


