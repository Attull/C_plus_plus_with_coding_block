#include<iostream>
#include<algorithm>
using namespace std;

int cal_pow(int b,int p)
{
    if(p==0)
        return 1;
    else
        return b*cal_pow(b,p-1);
}

int cal_pow_fast(int b,int p)
{
    if(p==0)
        return 1;

    int small_ans=cal_pow_fast(b,p/2);        //if power is even ,2^8
    small_ans*=small_ans;                     // 2^8=(2^4)^2

    if(p&1)                                   //if power is odd
    {
            small_ans=b*small_ans;            //2^9=2*(2^4)^2
    }
    return small_ans;
}

int main()
{
    int b,p;
    cin>>b;
    cin>>p;
    cout<<cal_pow(b,p)<<endl;
    cout<<cal_pow_fast(b,p);
    return 0;
}
