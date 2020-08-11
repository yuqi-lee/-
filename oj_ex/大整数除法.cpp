#include<stdio.h>
#include<string.h>

#define MAX_LEN 100

char szLine1[MAX_LEN + 10];
char szLine2[MAX_LEN + 10];

int an1[MAX_LEN + 10]; // 被除数
int an2[MAX_LEN + 10]; // 除数

int aResult[MAX_LEN + 10];

//   p1 - p2   ;结果放入 p1;   不够减则返回 -1; 正好减完返回 0; 否则返回结果的长度
int Substract(int* p1,int* p2,int nLen1,int nLen2)
{
    if(nLen1 < nLen2)
        return(-1);

    int i;
    int bLarger = 0;
    if(nLen1 == nLen2)
    {
        for(i = nLen1 - 1;i >= 0;i--)
        {
            if(p1[i] > p2[i])
            {
                bLarger = 1;
            }
            else if(p1[i] < p2[i])
            {
                if(!bLarger)
                {
                    return(-1);
                }
            }
        }
    }

    for(i = 0;i < nLen1;i++)
    {
        p1[i] -= p2[i];
        if(p1[i] < 0)
        {
            p1[i] += 10;
            p1[i+1]--;
        }
    }

    for(i = nLen1-1;i >= 0;i--)
    {
        if(p1[i])
            return(i+1);
        
    }
    return(0);

}

void print_int(int* p,int size)
{
    int i;
    for(i = size - 1;i >= 0;i--)
    {
        printf("%d",p[i]);
    }
    return;
}

int main()
{
    int t,n;
    char szBlank[20];
    scanf("%s",szLine1);
    scanf("%s",szLine2);
    int nLen1 = strlen(szLine1);
    int nLen2 = strlen(szLine2);

    

    int i,j;

    memset(an1,0,sizeof(an1));
    memset(an2,0,sizeof(an1));
    memset(aResult,0,sizeof(aResult));

    j = 0;
    for(i = nLen1 - 1;i >= 0;i--)
        an1[j++] = szLine1[i] - '0';
    j = 0;
    for(i = nLen2 - 1;i >= 0;i--)
        an2[j++] = szLine2[i] - '0';
    
    if(nLen1 < nLen2)
    {
        printf("0\n");
        print_int(an1,nLen1);
        return(0);
    }

    int _nLen1 = Substract(an1,an2,nLen1,nLen2);
    if(nLen1 < 0)
    {
        printf("0\n");
        print_int(an1,nLen1);
        return(0);
    }
    else if(_nLen1 == 0)
    {
        printf("1\n0");
        return(0);
    }
    nLen1 = _nLen1;
    aResult[0]++;
    int nTimes = nLen1 - nLen2;
    if(nTimes < 0)
        goto OutputResult;

    else if(nTimes > 0)
    {
        for(i = nLen1 - 1;i >= 0;i--)
        {
            if(i >= nTimes)
                an2[i] = an2[i - nTimes];
            else
                an2[i] = 0;

        }
    }
    nLen2 = nLen1;
    for(j = 0;j <= nTimes;j++)
    {
        int nTmp;

        while((nTmp = Substract(an1,an2+j,nLen1,nLen2-j)) >= 0)
        {
            nLen1 = nTmp;
            aResult[nTimes - j]++;
        }
    }

    OutputResult:
        for(i = 0;i < MAX_LEN;i++)
        {
            if(aResult[i] >= 10)
            {
                aResult[i+1] += aResult[i]/10;
                aResult[i] %= 10;

            }
        }
        int bStartOutput = 0;
        for(i = MAX_LEN;i >= 0;i--)
        {
            if(bStartOutput)
                printf("%d",aResult[i]);

            else if(aResult[i])
            {
                printf("%d",aResult[i]);
                bStartOutput = 1;
            }   
        }
        if(!bStartOutput)
            printf("0\n");
        printf("\n");
        print_int(an1,nLen1);

        return(0);
}