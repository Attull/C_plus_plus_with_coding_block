#include<iostream>
using namespace std;

int fib(int n)
{
    if(n==0 ||n==1)
        return n;

    int f1=fib(n-1);
    int f2=fib(n-2);;

    return f1+f2;
}

int fibb(int n)
{
    if(n<=1)
        return n;

    return fibb(n-1)+fibb(n-2);
}

int main()
{
    int n;
    cin>>n;

    cout<<fib(n);
    return 0;
}
