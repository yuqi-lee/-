#include<iostream>
using namespace std;
int main(){
    int arraylist[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int month1,month2,day1,day2;
    scanf("%d %d",&month1,&day1);
    scanf("%d %d",&month2,&day2);
    int sum = 0;
    if(month1 < month2)
    {
        sum += arraylist[month1] - day1;
        for(int i = month1+1 ; i < month2 ; i++)
            sum += arraylist[i];
        sum += day2;
    }
    else
        sum = day2 - day1;
    cout<<sum<<endl;
    return 0;
}
