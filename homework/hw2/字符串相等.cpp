#include<iostream>
using namespace std;

bool isSameString(char* s,char* t)
{
    int i = 0,j = 0;
    if(*s == '\0' && *t == '\0')
        return true;
    else if(*s == '\0' || *t == '\0')
        return false;
    else
    {
        for(; s[i] != '\0' && t[j] != '\0';)
        {
            if(s[i] == ' ' )        //遇到空格自动跳过
            {
                i++;
                continue;
            }
            else if( t[j] == ' ')   //遇到空格自动跳过
            {
                j++;
                continue;
            }
            else
            {   //判断两个非空格字符是否相等或互为大小写关系
                if(s[i] != t[j] && s[i] != t[j] + 32 && s[i] != t[j] - 32)
                    return false;
                i++;
                j++;
            }
                
        }

        /*判断未结束的字符串余下是否全为空格*/
        for(;s[i] != '\0';i++)
            if(s[i] != ' ')
                return false;
        
        for(;t[j] != '\0';j++)
            if(t[j] != ' ')
                return false;

        
        return true;
    }
    
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
    cout<<"\ns1与s2";
    isSameString(s1,s2) == true ? cout<<"相同" : cout<<"不同";
}