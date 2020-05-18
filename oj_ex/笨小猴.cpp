#include<iostream>
using namespace std;

bool isPrimeNumber(int num)
    {
        if(num == 0 || num == 1)    return false;
        //定义一个标记变量
        bool flag = true;        
        for(int i=2;i<num;i++) 
        {
            if(num%i == 0) 
            {
                flag=false;
                break;                    
            }
        }
        return flag;
    }
int main(){
    char* s;
    s = new char[100];
    int arrylist[26] = {0};
    scanf("%s",s);
    for(int i = 0; s[i] != '\0' ; i++)
        arrylist[(int)(s[i] - 'a')]++;
    int min = 101,max = 0;
    
    for(int i = 0; i<26 ; i++)
    {
        if(arrylist[i]<min && arrylist[i] != 0)
            min = arrylist[i];
        if(arrylist[i]>max)
            max = arrylist[i];
    }
    if(isPrimeNumber(max-min))
        cout<<"Lucky Word"<<endl<<(max-min)<<endl;
    else
        cout<<"No Answer"<<endl<<"0"<<endl;
}


