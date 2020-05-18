#include<iostream>
using namespace std;

bool isChildString(char* parent,char* child)
{
    int j = 0;
    int i = 0;
    for(; child[i] != '\0';)
    {
        for(;parent[j] != '\0';)
        {
            //在父串遍历完之前一直遍历搜索相同的字符
            if(parent[j] == child[i])
            {
                j++;
                i++;
                break;
            }
            j++;        
        }                    
        if(parent[j] == '\0' )   //若父串已遍历完，则直接break出循环
            break;
    }
    if(child[i] == '\0')    //若子串全部匹配完才退出，返回 true
        return true;
    else
        return false;
}

int main(void)
{
    /* 一个可能的输入程序 */
    char* s1,* s2;
    s1 = new char[100000];
    s2 = new char[100000];
    cout<<"输入s1串：";
    cin.getline(s1,100000);
    cout<<"\n输入s2串：";
    cin.getline(s2,100000);
    cout<<"\ns1";
    isChildString(s2,s1) == true ? cout<<"是" : cout<<"不是";
    cout<<"s2的子串";
}

