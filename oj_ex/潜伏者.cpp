#include<iostream>
using namespace std;

int main(){
    char* s1 = new char[100];
    char* s2 = new char[100];
    char* s3 = new char[100];
    char* arraylist = new char[26];
    bool* ifused = new bool[26];
    scanf("%s",s2);
    scanf("%s",s1);
    scanf("%s",s3);
    for(int i = 0 ; i < 26 ; i++ )  
    {
        arraylist[i] = '#';
        ifused[i] = false;
    }    
    int count = 0;
    for(int i = 0 ; s1[i] != '\0' ; i++ )
    {
        if(arraylist[(int)(s2[i] - 'A')] == '#')
        {
            if(ifused[(int)(s1[i] - 'A')] != false)
            {
                cout<<"Failed"<<endl;
                return 0;
            }
            else
            {
                arraylist[(int)(s2[i] - 'A')] = s1[i];
                count++;
                ifused[(int)(s1[i] - 'A')] = true;
            }
        }
        else
        {
            if(arraylist[(int)(s2[i] - 'A')] != s1[i])
            {
                cout<<"Failed"<<endl;
                return 0;
            }
        }
    }
    if(count != 26)
    {
        cout<<"Failed"<<endl;
        return 0;
    }
    char c;
    for(int i = 0 ; s3[i] != '\0' ; i++)
    {
        c = arraylist[(int)(s3[i] - 'A')];
        putchar(c);
    }
    cout<<endl;
    return 0;
}