#include<iostream>
using namespace std;

template<typename T>
class SqStack{
public:
    T* elem;
    int top;
    int maxsize;
    SqStack(int n);
    ~SqStack();
    int pop(T& e);
    int push(T e);
    bool ifempty();
};
template <typename T>
SqStack<T> :: SqStack(int n)
{
    elem = (T*)malloc(n*sizeof(T));
    top = -1;
    maxsize = n;
    return;
}

template<typename T>
int SqStack<T> ::pop(T& e)
{
    if(top == -1)
        return(-1);         //栈中元素均为自然数，返回负值时表明进行pop前栈已空    
    else
    {    
        e = elem[top];
        top--;
    }
    return(1);
}
template<typename T>
int SqStack<T>:: push(T e)
{
    if(top>=maxsize-1)
        exit(-1);
    else
    {
        top++;
        elem[top] = e;
    }
    return 1;  
}
template<typename T>
SqStack<T> :: ~SqStack()
{
    free(elem);
    maxsize = 0;
    top = -1;
    return;
}
template<typename T>
bool SqStack<T> :: ifempty()
{
    if(top == -1)
        return true;
    return false;
}