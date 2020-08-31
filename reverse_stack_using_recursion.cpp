#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &s,int data)
{
    //base case
    if(s.empty())
    {
        s.push(data);
        return;
    }

    //rec case
    int x=s.top();              //if there is already one element in stack then first store it and remove from stack
    s.pop();
    insert_at_bottom(s,data);   //recursive call which store required element in bottom of stack
    s.push(x);                  //push back the element which we remove above
}

void reverse_stack(stack <int> &s)
{
   //base case
    if(s.empty())
    {
        return;
    }

    //pop out the top element and insert it at the bottom of "reversed smaller stack"
    int x=s.top();
    s.pop();

    //rec reverse the smaller stack
    reverse_stack(s);
    insert_at_bottom(s,x);
}

int main()
{
    stack <int> s;
    int n=5;
    for(int i=0;i<n;++i)
        s.push(i+1);

    reverse_stack(s);

    for(int i=0;i<n;++i)
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}
