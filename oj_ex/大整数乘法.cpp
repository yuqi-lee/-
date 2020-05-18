#include<iostream>
#include<string.h>
#define MAX_LEN 100
unsigned an1[MAX_LEN + 10];
unsigned an2[MAX_LEN + 10];
unsigned aResult[MAX_LEN * 2 + 10];
char szline1[MAX_LEN + 10];
char szline2[MAX_LEN + 10];

using namespace std;

int main(){
    //gets(szline1);
    //gets(szline2);
    scanf("%s",szline1);
    scanf("%s",szline2);
    int i,j;
    int nLen1 = strlen(szline1);
    memset(an1, 0, sizeof(an1));
    memset(an2, 0, sizeof(an2));
    memset(aResult, 0, sizeof(aResult));
    j = 0;
    for(i = nLen1 - 1;i >= 0;i--)
        an1[j++] = szline1[i] - '0';
    int nLen2 = strlen(szline2);
    j = 0;
    for(i = nLen2 - 1;i >= 0;i--)
        an2[j++] = szline2[i] - '0';

    for(i = 0; i < nLen2; i++)
    {
        for(j = 0; j < nLen1; j++)
            aResult[i + j] += an2[i] * an1[j];
    }
    
    for(i = 0;i < MAX_LEN * 2;i++)
    {
        if(aResult[i] >= 10)
        {
            aResult[i + 1] += aResult[i] / 10;
            aResult[i] %= 10;
        }
    }

    bool bsoutput = false;
    for(i = MAX_LEN * 2; i >= 0 ; i--)
        if(bsoutput)
            printf("%d",aResult[i]);
        else if(aResult[i])
        {
            printf("%d",aResult[i]);
            bsoutput = true;
        }
    if(!bsoutput)
        cout<<"0";
    return 0;
            
}