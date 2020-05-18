#include<iostream>
#include<fstream>
typedef int status;
using namespace std;

status sort(int* array_1,int* array_2,int size);

int main()
{

    /*读取数据*/
    ifstream fin;
    fin.open("case.txt",ios_base::in);  //打开测试用例文件
    int length,block_num;
    fin>>length;
    fin>>block_num;
    int* begin = new int[block_num];    //begin记录起点位置，end 记录终点位置
    int* end = new int[block_num];
    for(int i = 0;i < block_num && !fin.eof(); i++)
    {
        fin>>begin[i];
        fin>>end[i];
    }
    fin.close();
    
    /*排序*/
    sort(begin,end,block_num);
    
    /*计算长度*/
    int sum = 0;
    int _begin,_end;        //_begin与_end 记录上一区域的起始位置
    _begin = begin[0];
    _end = end[0];
    for(int i = 1; i < block_num; i++)
    {
        if(begin[i] > _end)            //开启新的区域 ，并记录上一区域的长度
        {
            sum += _end - _begin + 1;
            _begin = begin[i];
            _end = end[i];
            continue;
        }
        _end = end[i] > _end ? end[i] : _end;   //判断是否需要延长记录
    }
    sum += _end - _begin + 1;

    /*将结果输出至文件*/
    ofstream fout;
    fout.open("result.txt",ios_base::out);
    fout<<length - sum + 1;
    fout.close();
    delete []begin;
    delete []end;
    return 0;
}

status sort(int* begin,int* end,int block_num)
{
    //冒泡排序
    //根据起点进行排序；起点需要交换时，终点数组做对应交换
    int temp;
    for(int i = 0; i < block_num; i++)
        for(int j = 0; j < block_num - i - 1; j++)
        {
            if(begin[j] > begin[j+1])
            {
                temp = begin[j];
                begin[j] = begin[j+1];
                begin[j+1] = temp;
                temp = end[j];
                end[j] = end[j+1];
                end[j+1] = temp;
            }
        }
    return(1);
}//sort