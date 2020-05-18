#include<iostream>
using namespace std;

int arraylist[41] = {0,1,1};

int getnumber(int index)
{
    if(arraylist[index] == 0)
    {
        arraylist[index] = getnumber(index-1) + getnumber(index-2);
        return(arraylist[index]);
    }
    else
        return(arraylist[index]);
}

int main(){
    int n;

    while(scanf("%d",&n) != EOF)
    {
        cout<<"The Fibonacci number for "<<n<<" is "<<getnumber(n)<<endl;
    }
    return 0;
}
