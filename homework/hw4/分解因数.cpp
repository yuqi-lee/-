/*
    李昱祁  PB18071496  程序设计II第 4 次作业

    题目 1：分解因数

                    2020.04.22
                                                */


#include <iostream>
using namespace std;

int _count = 0;
void my_func(int i, int a);

int main(void)
{
    int a;
    cout << "输入正整数a：";
    cin >> a;
    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            if (a / i >= i)     //后续的最大可能因子要大于i，才有效
            {
                _count++;
                my_func(i, a / i);  //计算 a/i 的分解种数
            }
            if (a == i)         //此时没有后续因子，直接计数加1
                _count++;
        }
    }
    cout << endl
         << "分解的种数为："
         << _count << " ";
    return (0);
}

void my_func(int i, int a)
{
    for (int j = i; j <= a; j++)
    {
        if (a % j == 0)
        {
            if (a / j >= j)
            {
                _count++;
                my_func(j, a / j);  //递归计算 a/i 的分解种数
            }
        }
        // a == i 的情况在上层函数中已经记录
    }
    return;
}