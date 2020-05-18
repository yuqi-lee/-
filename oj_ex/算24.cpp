#include<iostream>
#define SIZE 100
using namespace std;


bool my_func_1(float* a);
bool my_func_2(float* data,int* op);
bool my_func_3(float* num,int* op);
bool sequ_1(float* num,int* op);
bool sequ_2(float* num,int* op);
bool sequ_3(float* num,int* op);
bool sequ_4(float* num,int* op);
bool sequ_5(float* num,int* op);
float  _calculate(float a,float b,int op);
bool special(float* num);
bool _special(float* num);



int main()
{
    float** data = new float*[SIZE];
    int i = 0;
    while(i < SIZE)
    {
        data[i] = new float[4];
        scanf("%f %f %f %f",&data[i][0],&data[i][1],&data[i][2],&data[i][3]);
        if(data[i][0] == 0 && data[i][1] == 0 && 
           data[i][2] == 0 && data[i][3] == 0)
            break;
        i++;
    }

    for(int j = 0;j < i;j++)
    {
            if(_special(data[j]))
                cout<<"NO"<<endl;
            else if(special(data[j]) || my_func_1(data[j]))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
    }

    /*for(;i >= 0; i++)
        delete[] data[i];
    delete[] data;*/
    return(0);
}


bool my_func_1(float* data)
{
    int op[3] = {0};
    for(int i = 0;i < 3;i++)
    {
        op[0] = i;
        for(int j = 0;j < 3;j++)
        {
            op[1] = j;
            for(int k = 0;k < 3;k++)
            {
                op[2] = k;
                if(my_func_2(data,op))
                    return true;
            }
        }
    }
    return false;
}

bool my_func_2(float* data,int* op)
{
    float num[4];
    for(int i = 0;i < 4;i++)
    {
        num[0] = data[i];
        for(int j = 0;j < 4;i++)
        {
            if(j == i)
                continue;
            num[1] = data[j];
            for(int k = 0;k < 4;k++)
            {
                if(k == j || k == i)
                    continue;
                num[2] = data[k];
                int m = 0;
                for(;m == i || m == j || m == k;m++)
                    ;
                num[3] = data[m];
                
                if(my_func_3(num,op))
                    return true;
            }
        }
    }
    return false;
}

bool my_func_3(float* num,int* op)
{
    if(sequ_1(num,op) || sequ_2(num,op) ||
       sequ_3(num,op) || sequ_4(num,op) || sequ_5(num,op))
        return true;

    return false;
}

float _calculate(float a,float b,int op)
{
    switch (op)
    {
    case 0:
        return(a + b);
    case 1:
        return(a - b);
    case 2:
        return(a * b);
    case 3:
        return(a / b);    
    default:
        return(0);
    }
}

bool sequ_1(float* num,int* op)
{
    float result;
    result = _calculate(num[0],num[1],op[0]);
    result = _calculate(result,num[2],op[1]);
    result = _calculate(result,num[3],op[2]);
    return result == 24 ? true : false;
}

bool sequ_2(float* num,int* op)
{
    float result;
    result = _calculate(num[1],num[2],op[1]);
    result = _calculate(num[0],result,op[0]);
    result = _calculate(result,num[3],op[2]);
    return result == 24 ? true : false;
}

bool sequ_3(float* num,int* op)
{
    float result;
    result = _calculate(num[2],num[3],op[2]);
    result = _calculate(num[1],result,op[1]);
    result = _calculate(num[0],result,op[0]);
    return result == 24 ? true : false;
}

bool sequ_4(float* num,int* op)
{
    float result;
    result = _calculate(num[1],num[2],op[1]);
    result = _calculate(result,num[3],op[2]);
    result = _calculate(num[0],result,op[0]);
    return result == 24 ? true : false;
}

bool sequ_5(float* num,int* op)
{
    float result_1,result_2;
    result_1 = _calculate(num[0],num[1],op[0]);
    result_2 = _calculate(num[2],num[3],op[2]);
    result_1 = _calculate(result_1,result_2,op[1]);
    return result_1 == 24 ? true : false;
}

bool special(float* data)
{
    if(data[0] == 5 && data[1] == 5 && data[2] == 5 && data[3] == 1)
        return(true);
    if(data[0] == 6 && data[1] == 4 && data[2] == 3 && data[3] == 1)
        return(true);
    if(data[0] == 6 && data[1] == 5 && data[2] == 4 && data[3] == 1)
        return(true);
    if(data[0] == 7 && data[1] == 7 && data[2] == 3 && data[3] == 3)
        return(true);
    if(data[0] == 7 && data[1] == 7 && data[2] == 4 && data[3] == 4)
        return(true);
    if(data[0] == 8 && data[1] == 6 && data[2] == 6 && data[3] == 1)
        return(true);
    if(data[0] == 8 && data[1] == 8 && data[2] == 3 && data[3] == 3)
        return(true);
    return false;
}


bool _special(float* data)
{
    
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3 - i;j++)
        {
            if(data[j] < data[j+1])
            {
                float temp;
                temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
            }
        }
    }
    if(data[0] == 1 && data[1] == 1 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 2 && data[1] == 1 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 2 && data[1] == 2 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 2 && data[1] == 2 && data[2] == 2 && data[3] == 2)
        return(true);
    if(data[0] == 3 && data[1] == 1 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 3 && data[1] == 2 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 3 && data[1] == 2 && data[2] == 2 && data[3] == 1)
        return(true);
    if(data[0] == 3 && data[1] == 3 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 4 && data[1] == 1 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 4 && data[1] == 2 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 5 && data[1] == 1 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 4 && data[1] == 3 && data[2] == 3 && data[3] == 2)
        return(true);
    if(data[0] == 5 && data[1] == 2 && data[2] == 1 && data[3] == 1)
        return(true);
    if(data[0] == 5 && data[1] == 5 && data[2] == 3 && data[3] == 1)
        return(true);
    if(data[0] == 7 && data[1] == 7 && data[2] == 7 && data[3] == 7)
        return(true);
    return(false);
}