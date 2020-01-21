#include<iostream>
#include<algorithm>
using namespace std;

int lower_bd(int arr[],int n,int ele)
{

    int beg=0,last=n-1;
    int mid,ans=-1;

    while(beg<=last)
    {
        mid=(beg+last)/2;
        if(ele==arr[mid])
        {
            ans=mid;
            beg=mid+1;
        }
        else if(ele<arr[mid])
        {
            last=mid-1;
        }
        else
            beg=mid+1;
    }
    return ans;
}

int main()
{
    int arr[]={2,3,3,7,3,12,76};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ele;
    sort(arr,arr+n);

    cout<<"enter element to find its last occurrence/upper bound \n";
    cin>>ele;
    int ans=lower_bd(arr,n,ele);


    cout<<"last occurrence of given element is : "<<ans;

    return 0;
}
