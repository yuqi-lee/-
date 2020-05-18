#include<iostream>
using namespace std;

bool isChildString(char* parent,char* child)
{
    int j = -1;
    int i = 0;
    for(; child[i] != '\0';i++)
    {
        if(j != -1 && parent[j] == '\0')
            break;
        for(;parent[j] != '\0';)
        {
            j++;
            if(parent[j] == child[i])
            {
                break;
            }
        }
    }
    if(child[i] == '\0')
        return true;
    else
        return false;
}

int main(void)
{
    /* 一个可能的输入程序 */
    char* s1,* s2;
    s1 = new char[100];
    s2 = new char[100];
    cout<<"输入s1串：";
    cin.getline(s1,100);
    cout<<"\n输入s2串：";
    cin.getline(s2,100);
    cout<<"\ns1";
    isChildString(s1,s2) == true ? cout<<"是" : cout<<"不是";
    cout<<"s2的子串";
}

