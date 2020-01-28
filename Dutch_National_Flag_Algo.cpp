#include<iostream>
#include<algorithm>
using namespace std;

void sort_0_1_2(int a[],int n)
{
    int s=0;                //take 's' to point to start of array
    int e=n-1;              //take 'e' to point to end of array
    int mid=0;

    while(mid<=e)
    {
        if(a[mid]==1)
        {
            mid++;
        }
        else if(a[mid]==2)
        {
            swap(a[mid],a[e]);
            e--;
        }
        else
        {
            swap(a[mid],a[s]);
            mid++;
            s++;
        }
    }

    for(int i=0;i<n;++i)
    {
        cout<<a[i];
    }
}
int main()
{
    int a[1000];
    int n;
    cin>>n;

    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }


    sort_0_1_2(a,n);
}
