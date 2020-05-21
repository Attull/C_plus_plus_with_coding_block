#include<iostream>
#include<stack>
using namespace std;

void transfer(stack <int> & s1,stack <int> & s2)
{
    int n=s1.size();
    for(int i=0;i<n;++i)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void reverse_stack(stack <int> &s1)
{
    stack <int> s2;
    stack <int> s3;
    transfer(s1,s2);
    transfer(s2,s3);
    transfer(s3,s1);
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
    s1.push(11);
    s1.push(2);
    s1.push(30);
    cout<<"orginal list is :"<<print(s1);
    reverse_stack(s1);
    cout<<"reverse list is : ";
    print(s1);
    return 0;
}
