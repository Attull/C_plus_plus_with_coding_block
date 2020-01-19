#include<iostream>
#include<algorithm>
using namespace std;

void rain(int a[1000],int n)
{
    int l[n],r[n];

//finding leftmost highest element for each element using predefined function
    l[0]=a[0];
    for(int i=1;i<n;++i)
    {
        l[i]=max(l[i-1],a[i]);
    }

//finding rightmost highest element for each element
    int rh=0;
    for(int i=n-1;i>=0;--i)
    {
        if(a[i]>=rh)
         {
             rh=a[i];
             r[i]=a[i];
         }
        else
            r[i]=rh;
    }

    cout<<"leftmost highest value for given array \n";
    for(int i=0;i<n;++i)
        cout<<l[i]<<" ";

    cout<<"\nrightmost highest value for given array \n";
    for(int i=0;i<n;++i)
        cout<<r[i]<<" ";

    int temp=0;
    for(int i=0;i<n;++i)
    {
        int m=min(l[i],r[i]);
        temp+=m-a[i];
    }
    cout<<"\nMaximum water that can be accumulated is ";
    cout<<temp;
}
int main()
{
    int n;
    cout<<"Number of element in array \n";
    cin>>n;

    int a[1000];
    cout<<"enter values for array \n";
    for(int i=0;i<n;++i)
        cin>>a[i];

    rain(a,n);
    return 0;
}
