#include<iostream>
using namespace std;

int main()
{
    int num,no;
    cin>>num;                     //enter number of element

    int a[64]={0};

    for(int i=0;i<num;++i)
    {
        cin>>no;                 //take every number one by one and find there bits some
        int j=0;
        while(no)
        {
            int last_bit=(1&no);
            a[j]+=last_bit;
            no=no>>1;
            ++j;
        }
    }

    int res=0;
    int p=1;
    for(int i=0;i<64;++i)
    {
        a[i]%=3;                  //check for 3N and 3N+1 form

        //convert binary to decimal;
        res+=p*a[i];              //2*2*a[2] +2*a[1]+1*a[0];
        p=p<<1;                  //increase p in power of 2
    }

    cout<<res;
    return 0;

}

