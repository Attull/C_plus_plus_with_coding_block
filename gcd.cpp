#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a,int b)                  //basic method
{
    int res=0;
    int temp=min(a,b);                //find the minimum of two and run loop till minimum value
    for(int i=1;i<=temp;++i)
    {
        if(a%i==0 && b%i==0)
            res=i;
    }
    return res;
}

int gcd_opt(int a,int b)                //euclid algorithm
{
    return b==0 ? a : gcd(b,a%b);
}

//GCD*LCM =A*B

int lcm(int a,int b)
{
    return a*b/gcd_opt(a,b);
}

int main()
{
    int a,b;
    cin>>a;
    cin>>b;

    cout<<gcd(a,b)<<endl;
    cout<<gcd_opt(a,b)<<endl;
    cout<<lcm(a,b)<<endl;
}
