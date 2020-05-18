/*
    李昱祁  PB18071496  程序设计II第 3 次作业

    题目 1：计算 2 的 N 次方

                    2020.04.02
                                                */



#include<iostream>
#define SIZE 50
using namespace std;


long my_func(int n);
int* large_int_add(int* s1,int* s2);
void my_print(int* output,int size);

int main()
{
    cout<<endl<<"===============计算 2 的 N 次方================="<<endl<<endl;
    int n;
    cout<<"请输入 N: ";
    cin>>n;
    cout<<endl<<"计算 2 的 "<<n<<" 次方为 :";
    if(n < 63)
        cout<<my_func(n)<<endl;
    else
    {
        /* 
            先计算 2 的 62 次方，并将其按逆序放入一个 int 型数组
            数组中每个元素表示大整数十进制的一位
                                                    */
        long _pow62 = my_func(62);
        int* array_1 = new int[SIZE];
        for(int k = 0; k < SIZE ; k++)
            array_1[k] = 0;
        for(int i = 0; _pow62 > 0 ; i++)
        {
            array_1[i] = _pow62 % 10;
            _pow62 = _pow62 / 10;
        }

        /*      利用大整数相加运算，计算更高次幂        */
        for(int j = n - 62; j > 0 ; j--)
        {
            int* temp = array_1;
            array_1 = large_int_add(array_1,array_1);
            delete[] temp;
        }
        my_print(array_1,SIZE);
        cout<<endl;
    }
    return 0;
}

int* large_int_add(int* s1,int* s2)
{
    /*
        输入两个 int 型数组中存放的大整数，并计算它们的和
        结果放入数组中返回          
                                */
    int* result = new int[SIZE];
    for(int k = 0; k < SIZE - 1 ; k++)
        result[k] = 0;
    for(int i = 0; i < SIZE ;i++)
    {
        result[i] = s1[i] + s2[i];
    }

    /*     计算进位     */
    for(int i = 0; i < SIZE - 1 ;i++)
    {
        if(result[i] > 9)
        {
            result[i] = result[i] % 10;
            result[i + 1] += 1;
        }
    }
    return result;
}//large_int_add


long my_func(int n)
{
    /*
        小于  2^63 的数，可以用 long 型表示
        直接使用左移计算
                                */
    long x = 2;
    for(; n > 1 ; n--)
    {
        x = x << 1;
    }
   return(x); 
}//my_func


void my_print(int* output,int size)
{
    /*
        根据定义的大整数表达格式，将其输出
                                */
    int i = size - 1;

    /*  略去非有效数字的 0  */
    for( ; i >= 0 && output[i] == 0 ; )     
        i--;


    for( ; i >= 0 ; i--)
        cout<<output[i];
    return;
}//my_print