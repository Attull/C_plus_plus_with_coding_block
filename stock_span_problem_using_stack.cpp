#include<iostream>
#include<stack>
using namespace std;

void stock_span(int prices[],int n,int span[])
{
    stack <int> s;                //store index of the days
    s.push(0);

    //bcoz span value of first element is always zero
    span[0]=1;

    //calculate span value for restof the elements
    for(int i=1;i<=n-1;++i)
    {
        int current_price=prices[i];

        while(!s.empty() and prices[s.top()]<=current_price)
           s.pop();

    if(!s.empty())
    {
        int prev_highest=s.top();
        span[i]=i-prev_highest;
    }
    else
    {
        span[i]=i+1;
    }

    //push this element to stack
    s.push(i);
}

int main()
{
    int prices[]={100,80,60,70,60,75,85};
    int nl=sizeof(prices)/sizeof(int);
    int span[10000]={0};


}
