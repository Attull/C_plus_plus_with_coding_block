//find the given element in the rotated array

#include<iostream>
using namespace std;

int find_ele(int a[],int n,int key)
{
    int s=0;
    int e=n-1;

    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[s]<=a[mid])                       //means left part is sorted and we can find our element here
        {
            if(a[s]<=key && key<=a[mid])
                e=mid-1;
            else
                s=mid+1;
        }
        else
        {
            if(a[mid]<=key && key<=a[e])
                s=mid+1;
            else
                e=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[10000];
    int n;
    cout<<"enter the size of array \n";
    cin>>n;

    cout<<"enter array element \n";
    for(int i=0;i<n;++i)
        cin>>arr[i];

    int key;
    cout<<"enter the element to search \n";
    cin>>key;

    int index=find_ele(arr,n,key);

    cout<<index;
}
