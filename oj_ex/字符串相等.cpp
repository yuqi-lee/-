#include<iostream>
using namespace std;

bool isSameString(char* s,char* t)
{
    if(*s == '\0' && *t == '\0')
        return true;
    else if(*s == '\0' || *t == '\0')
        return false;
    else
    {
        for(int i = 0,j = 0; s[i] != '\0' && t[j] != '\0';)
        {
            if(s[i] == ' ' )
            {
                i++;
                continue;
            }
            else if( t[j] == ' ')
            {
                j++;
                continue;
            }
            else
            {
                if(s[i] != t[j] && s[i] != t[j] + 32 && s[i] != t[j] - 32)
                    return false;
                i++;
                j++;
            }
                
        }
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