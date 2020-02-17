#include<iostream>
using namespace std;

int find_exp(int n,int p)
{
    int ans=1;
    while(p)
    {
        int last_bit=(p&1);    //find last bit
        if(last_bit)            //if last bit set
        {
            ans=ans*n;
        }
        p=p>>1;                //right shift power value
        n=n*n;
    }
    return ans;
}
int main()
{
    int n,p;
    cout<<"enter the number \n";
    cin>>n;
    cout<<"enter exponent value \n";
    cin>>p;
    cout<<"Answer \t";
    cout<<find_exp(n,p);

    return 0;
}
