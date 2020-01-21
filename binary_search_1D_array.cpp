#include<iostream>
#include<algorithm>
using namespace std;

int binary_srch(int arr[],int n,int s)
{

    int beg=0,last=n-1;
    int mid;

    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(s==arr[mid])
        {
            return mid;
        }
        else if(s<arr[mid])
        {
            last=mid-1;
        }
        else
            beg=mid+1;
    }
    return -1;
}

int main()
{
    int arr[]={2,3,56,7,8,12,76};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s;
    sort(arr,arr+n);

    cout<<"enter element to search \n";
    cin>>s;
    int index=binary_srch(arr,n,s);

    if(index<0)
        cout<<"not found\n";
    else
        cout<<"found at index "<<index;

    return 0;
}
