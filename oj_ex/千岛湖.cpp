#include<iostream>
using namespace std;

void AscertainThisIsland(int i,int j,int size,bool** visited,char** lake)
{
    visited[i][j] = true;
    if(i-1 >= 0 && lake[i-1][j] == '*' && visited[i-1][j] == false)
        AscertainThisIsland(i-1,j,size,visited,lake);
    else if(i+1 < size && lake[i+1][j] == '*' && visited[i+1][j] == false)
        AscertainThisIsland(i+1,j,size,visited,lake);
    else if(j-1 >= 0 && lake[i][j-1] == '*' && visited[i][j-1] == false)
        AscertainThisIsland(i,j-1,size,visited,lake);
    else if(j+1 < size && lake[i][j+1] == '*' && visited[i][j+1] == false)
        AscertainThisIsland(i,j+1,size,visited,lake);

    return;
}
int main(){
    char** input = new char*[1001];
    input[0] = new char[1001];
    scanf("%s",input[0]);
    int size = 0;
    //确定湖的面积参数n
    for(; input[0][size] != '\0' ; size++)
        ;
    
    for(int i = 1 ; i < size ; i++)
    {
        input[i] = (char*)malloc(sizeof(char) * size); 
        scanf("%s",input[i]);
    }
    
    /*创建记录访问情况的visited数组，并初始化之*/
    bool** visited = (bool**)malloc(sizeof(bool*) * size);
    for(int i = 0 ; i < size ; i++)
    {
        visited[i] = (bool*)malloc(sizeof(bool) * size);
        for(int j = 0 ; j < size ; j++)
            visited[i][j] = false;
    }
    
    int count = 0;

    for(int m = 0; m < size ; m++)
    {
        for(int n = 0; n < size ; n++)
        {
            if(visited[m][n] == false )
            {
                visited[m][n] = true;
                if(input[m][n] == '*')  //若是一块新岛，则下一步确定整块岛屿的大小，并计数
                {
                    AscertainThisIsland(m,n,size,visited,input);
                    count++;
                    //cout<<"第"<<count<<"个岛坐标 ：("<<m<<","<<n<<")"<<endl;
                }    
            }
        }
    }
    cout<<count<<endl;
    return 0;
}