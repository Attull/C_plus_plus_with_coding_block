#include<iostream>
#include<algorithm>
using namespace std;

float sqrt(float num,int p)
{

    int beg=0,last=num;
    float mid,ans=-1;

    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(num==(mid*mid))
        {
            ans=mid;
            return ans;
        }
        else if(num >(mid*mid))
        {
            beg=mid+1;
            ans=mid;
        }
        else
            last=mid-1;
    }

    //for fractional part
    float inc=0.1;
    for(int i=0;i<p;++i)
    {
        while((ans*ans)<=num)
        {
            ans+=inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}

int main()
{
    float num;
    cout<<"enter element to find its square root \n";
    cin>>num;

    float t=sqrt(num,3);
    cout<<t;
/*
    if(index<0)
        cout<<"not found\n";
    else
        cout<<"found at index "<<index;
*/
    return 0;
}
