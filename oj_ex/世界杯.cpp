#include<iostream>
using namespace std;

struct team
{
    int score;
    int ball;
    int ball_win;
    int ball_lose;
    int paiming;
};

bool compare(team& t1,team& t2)
{
    if(t1.score > t2.score)
        return(true);
    else if(t1.score < t2.score)
        return(false);
    else
    {
        if(t1.ball > t2.ball)
            return(true);
        else if(t1.ball < t2.ball)
            return(false);
        else
        {
            if(t1.ball_win > t2.ball_win)
                return(true);
            else
                return(false);
            /* code */
        }    
        /* code */
    }
}

int main()
{
    char array[18];
    for(int i = 0;i < 18;i++)
    {
        cin>>array[i];
    }
    int list[12];
    for(int i = 0;i < 6;i++)
    {
        list[i*2] = array[i*3] - '0';
        list[i*2 + 1] = array[i*3 + 2] - '0';
    }

    team _team[4];
    for(int i = 0;i < 4;i++)
    {
        _team[i].score = 0;
        _team[i].ball = 0;
        _team[i].ball_win = 0;
        _team[i].ball_lose = 0;
    }
        
    _team[0].score += list[0] > list[1] ? 3 : (list[0] == list[1] ? 1 : 0);
    _team[0].score += list[4] > list[5] ? 3 : (list[4] == list[5] ? 1 : 0);
    _team[0].score += list[11] > list[10] ? 3 : (list[11] == list[10] ? 1 : 0);

    _team[1].score += list[1] > list[0] ? 3 : (list[1] == list[0] ? 1 : 0);
    _team[1].score += list[7] > list[6] ? 3 : (list[7] == list[6] ? 1 : 0);
    _team[1].score += list[8] > list[9] ? 3 : (list[8] == list[9] ? 1 : 0);

    _team[2].score += list[2] > list[3] ? 3 : (list[2] == list[3] ? 1 : 0);
    _team[2].score += list[5] > list[4] ? 3 : (list[5] == list[4] ? 1 : 0);
    _team[2].score += list[9] > list[8] ? 3 : (list[9] == list[8] ? 1 : 0);

    _team[3].score += list[3] > list[2] ? 3 : (list[3] == list[2] ? 1 : 0);
    _team[3].score += list[6] > list[7] ? 3 : (list[6] == list[7] ? 1 : 0);
    _team[3].score += list[10] > list[11] ? 3 : (list[10] == list[11] ? 1 : 0);

    _team[0].ball_win += list[0] + list[4] + list[11];
    _team[1].ball_win += list[1] + list[7] + list[8];
    _team[2].ball_win += list[2] + list[5] + list[9];
    _team[3].ball_win += list[3] + list[6] + list[10];

    _team[0].ball_lose += list[1] + list[5] + list[10];
    _team[1].ball_lose += list[0] + list[6] + list[9];
    _team[2].ball_lose += list[3] + list[4] + list[8];
    _team[3].ball_lose += list[2] + list[7] + list[11];

    for(int i = 0;i < 4;i++)
    {
        _team[i].ball = _team[i].ball_win - _team[i].ball_lose;
    }

    int first,second,third,forth;
    first = 0;
    for(int i = 1;i < 4;i++)
    {
        first = compare(_team[first],_team[i]) == true ? first : i;
    }
    _team[first].paiming = 1;

    forth = 0;
    for(int i = 1;i < 4;i++)
    {
        forth = compare(_team[forth],_team[i]) == false ? forth : i;
    }
    _team[forth].paiming = 4;

    for(int i = 0;i < 4;i++)
    {
        if(i != first && i != forth)
            third = i;
    }
    
    for(int i = 0;i < 4;i++)
    {
        if(i != first && i != forth && i != third)
            second = i;
    }

    if(compare(_team[second],_team[third]) != true)
    {
        int temp = second;
        second = third;
        third = temp;
    }
    _team[second].paiming = 2;
    _team[third].paiming = 3;

    for(int i = 0;i < 4;i++)
    {
        cout<<_team[i].paiming<<" "<<_team[i].score;
        cout<<" ";
        if(_team[i].ball >= 0)
            cout<<"+";
        cout<<_team[i].ball<<" "<<_team[i].ball_win<<" "<<_team[i].ball_lose;
        if(_team[i].paiming < 3)
            cout<<" Y\n";
        else
            cout<<" N\n";
    }
}