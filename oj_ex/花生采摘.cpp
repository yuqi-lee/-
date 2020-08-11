#include<iostream>
using namespace std;

/*
    本次oj，最坑的题目！没有之一！
    注意到开始的文字叙述说了下一次一定要采摘剩下的中，最多的那一个！
*/

struct location{
    int x;
    int y;
    int num;
    bool visited;
};

int find_max(location* array,int size);
int find_path(bool* visit,location* array,int i,int size,int time);
void set_visit(bool* visit,int size); 



int main()
{
    int m,n,time,num;
    
    scanf("%d %d %d",&m,&n,&time);
    location array[m*n];

    int k = 0;
    for(int i = 1;i <= m; i++)
    {
        for(int j = 1;j <= n; j++)
        {
            scanf("%d",&num);
            if(num != 0)
            {
                array[k].x = i;
                array[k].y = j;
                array[k].num = num;
                array[k].visited = false;
                k++;
            }
        }
    }

    
    int sum = 0;
    
    int i = find_max(array,k);
    if(time - 2 * array[i].x <= 0)
    {
        cout<<sum;
        return(0);
    }
        

    time -= (array[i].x + 1);
    sum += array[i].num;
    array[i].visited = true;
    
    while(true)
    {
        int j = find_max(array,k);
        if(j == -1)
            break;
        int x = array[i].x > array[j].x ? array[i].x - array[j].x : array[j].x - array[i].x;
        int y = array[i].y > array[j].y ? array[i].y - array[j].y : array[j].y - array[i].y;
        int distance = x + y;

        if(time - (distance+1+array[j].x) >= 0)
        {
            time -= (distance + 1);
            sum += array[j].num;
            array[j].visited = true;
            i = j;
        }
        else 
            break;
    }

    cout<<sum;

    return 0;
}


int find_path(bool* visit,location* array,int i,int size,int time)
{
    if(array[i].x  >= time) //等于也不可，否则没有采摘时间
        return 0;
    
    int _time = time - 1;
    visit[i] = true;
    
    int max_sum = array[i].num;

    for(int j = 0;j < size;j++)
    {
        if(visit[j] == false)
        {
            int sum = array[i].num;

            //计算距离差
            int x = array[i].x > array[j].x ? array[i].x - array[j].x : array[j].x - array[i].x;
            int y = array[i].y > array[j].y ? array[i].y - array[j].y : array[j].y - array[i].y;
            int distance = x + y;

            sum += find_path(visit,array,j,size,_time - distance);
            visit[j] = false;
            max_sum = sum > max_sum ? sum : max_sum;
        }
    }

    return(max_sum);

}

void set_visit(bool* visit,int size)
{

    for(int i = 0;i < size;i++)
        visit[i] = false;
    
    return;
}

int find_max(location* array,int size)
{
    int max = 0;
    int j = -1;
    for(int i = 0;i < size;i++)
    {
        if(array[i].visited == false && array[i].num > max)
        {
            max = array[i].num;
            j = i;
        }
    }
    return(j);
}

