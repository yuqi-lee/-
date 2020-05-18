#include<iostream>
using namespace std;
int main(){
    int input,output = 0;
    scanf("%d",&input);
    output += input%10;
    
    for(int i = 10,n = 1 ; n<=6 ; i*=10,n+=1)
        output += (input/i % 10)*(2<<(3*n-1)); 
    cout<<output<<endl;
    
}