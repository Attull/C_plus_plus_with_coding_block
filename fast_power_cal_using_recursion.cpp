#include<iostream>
using namespace std;

int power(int a,int n)                               //time complexity - O(n)
{
    if(n==0)
        return 1;

    return a*power(a,n-1);
}

int fast_power(int a,int n)                          //time complexity -O(log(n))
{
   //base case
    if(n==0)
        return 1;

    int sub_problem=fast_power(a,n/2);               //first we reach to base case
    sub_problem*=sub_problem;

    if(n&1)                                          //if power is odd
    {
        return a*sub_problem;
    }
    return sub_problem;
}

int main()
{
    int a,n;
    cin>>a>>n;

    cout<<power(a,n)<<endl;

    cout<<fast_power(a,n)<<endl;
    return 0;
}
