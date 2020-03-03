#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int arr[],int n)
{
    if(n==1)
        return;

    for(int i=0;i<n-1;++i)
    {
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    bubble_sort(arr,n-1);
}

void bubble_sort2(int arr[],int j,int n)
{
    if(n==1)
        return;
    if(j==n-1)
        return bubble_sort2(arr,0,n-1);

    if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);

    bubble_sort2(arr,j+1,n);
    return;
}
int main()
{
    int arr[]={2,3,56,7,8,12,76};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble_sort2(arr,0,n);
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
}
