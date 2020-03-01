#include<iostream>
using namespace std;

void dec(int n)
{
    if(n==0)
        return;
    else
    {
        cout<<n<<" ";
        dec(n-1);
    }
}
void inc(int n)
{
    if(n==0)
        return;
    else
    {
        inc(n-1);
        cout<<n<<" ";
    }
}
int main()
{
    int n;
    cin>>n;

    inc(n);
    cout<<endl;
    dec(n);
    return 0;
}
