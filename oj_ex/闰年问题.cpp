#include<iostream>
using namespace std;

int main(){
    int year;
    scanf("%d",&year);
    if(year%4 != 0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        if(year%100 != 0)
            cout<<"YES"<<endl;
        else
        {
            if(year%400 !=0 )
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }    
    } 
    return(0);
}