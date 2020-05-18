#include <iostream>
using namespace std;

void _counter(long* arraylist, long n, long i);

int main()
{
    long i, j;
    while (scanf("%ld %ld", &i, &j) != EOF)
    {
        long num = j - i + 1;
        long arraylist[num];
        long counter = 0;
        for (long k = 0; k < num; k++)
        {
            _counter(arraylist, k, i);
            counter = arraylist[k] > counter ? arraylist[k] : counter;
        }
        cout << i << " " << j << " " << counter << endl;
    }
    return(0);
}

void _counter(long* arraylist, long n, long i)
{
    long counter = 0;

    long number = n + i;
    while (true)
    {
        counter++;
        if (number == 1)
            break;
        else if (number % 2 == 0)
            number = number / 2;
        else
            number = number * 3 + 1;
    }
    arraylist[n] = counter;
    return;
}
