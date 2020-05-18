#include<iostream>
using namespace std;
int func(int n)
{
    if(n < 8)
        return(n);
    else
        return(n%8 + 10*func(n/8));
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF)
    {
        cout<<func(n)<<endl;
    }
}