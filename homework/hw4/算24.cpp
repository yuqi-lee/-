/*
    李昱祁  PB18071496  程序设计II第 4 次作业

    题目 2：算 24

                    2020.04.22
                                                */

#include <iostream>
#include <cmath>
using namespace std;

double arraylist_1[5];
#define EPS 1e-6

bool isEqual(double x, double y);           //比较两个double型数据是否相等
bool Count24(double *arraylist, int n);     //判断数组中的n个元素可否计算出24

int main(void)
{
    while (true)
    {
        for (int i = 0; i < 4; i++)
            cin >> arraylist_1[i];
        if (isEqual(arraylist_1[0], 0) && isEqual(arraylist_1[1], 0) &&
            isEqual(arraylist_1[2], 0) && isEqual(arraylist_1[3], 0)    )
            break;
        if (Count24(arraylist_1, 4))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return (0);
}

bool isEqual(double x, double y)
{
    return (fabs(x - y) <= EPS);
}

bool Count24(double* arraylist_1, int n)
{
    //若只有一个数，则即为运算结果
    if (n == 1)     
        return (isEqual(arraylist_1[0], 24));
    
    
    double arraylist_2[5];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int m = 0;
            for (int k = 0; k < n; k++)
            {
                //将数组中的数挑出两个，余下的拷贝入数组2中
                if (k != i && k != j)
                {
                    arraylist_2[m] = arraylist_1[k];
                    m++;
                }
            }
            //将挑出的两个数按加、减、乘、除计算到的结果也放入数组2
            arraylist_2[m] = arraylist_1[i] + arraylist_1[j];
            if (Count24(arraylist_2, m + 1))
                return (true);
            arraylist_2[m] = arraylist_1[i] - arraylist_1[j];
            if (Count24(arraylist_2, m + 1))
                return (true);
            arraylist_2[m] = arraylist_1[j] - arraylist_1[i];
            if (Count24(arraylist_2, m + 1))
                return (true);
            arraylist_2[m] = arraylist_1[j] * arraylist_1[i];
            if (Count24(arraylist_2, m + 1))
                return (true);
            //注意除法要考虑运算顺序
            if (!isEqual(arraylist_1[i], 0))    
            {
                arraylist_2[m] = arraylist_1[j] / arraylist_1[i];
                if (Count24(arraylist_2, m + 1))
                    return (true);
            }
            if (!isEqual(arraylist_1[j], 0))
            {
                arraylist_2[m] = arraylist_1[i] / arraylist_1[j];
                if (Count24(arraylist_2, m + 1))
                    return (true);
            }
        }
    }
    return (false);
}
