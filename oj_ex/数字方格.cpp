#include<iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int max_sum = 0;
    for(int i = n; i >= 0 ; i-- )
        for(int j = n; j >= 0 ; j--)
        {
            if(i+j >= 2 && (i+j) % 2 == 0)
                for(int k = n; k >= 0; k--)
                {
                    if(j+k >= 3 && (j+k) % 3 == 0
                        && (i+j+k) % 5 == 0)
                        if(max_sum < i+j+k)
                            max_sum = i+j+k;   
                }
        }
    cout<<max_sum;
    return 0;
}