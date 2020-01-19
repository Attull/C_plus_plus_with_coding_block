#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;

    int a[100000];
    cin>>n;

    for(int j=0;j<n;++j)
        cin>>a[j];

    int temp=0;
    for(int j=0;j<n-1;++j)
        for(int i=0;i<n-j-1;++i)           //n-j-1 bcoz after each time last elements are going to be sort
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }

        for(int i=0;i<n;++i)
            cout<<a[i]<<" ";


    return 0;
}
