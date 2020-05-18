#include<iostream>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            cout<<1<<endl;
        else
            cout<<(2<<(n-1))<<endl;
    }
    return 0;
}


