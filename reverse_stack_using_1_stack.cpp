#include<iostream>
#include<stack>
using namespace std;

void transfer(stack <int> & s1,stack <int> & s2,int n)
{
    for(int i=0;i<n;++i)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void reverse_stack(stack <int> &s1)
{
    stack <int> s2;
    int n=s1.size();
    for(int i=0;i<n;++i)
    {
        int k=s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(k);
        transfer(s2,s1,n-i-1);
    }
}

void print(stack <int> &s1)
{
    stack <int> s=s1;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack <int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    print(s1);
    reverse_stack(s1);
    print(s1);
    return 0;
}
