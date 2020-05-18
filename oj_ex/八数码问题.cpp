#include<iostream>
using namespace std;

bool isRingtPosition(int i,int j,int n);

int main(void)
{
    int table[3][3];
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            cin >> table[i][j];
    
    return(0);
}


//3*(2-i)+2-j
bool isRingtPosition(int i,int j,int n)
{
    return(n == 3*(2 - i) + 2 - j);
}