// give an array, find the number of inversions of it. if (i<j) and (a[i] >a[j] ) then the pair is called an inversion of an array A.
//We need to count all such pairs in the array
#include<iostream>
using namespace std;

int mergee(int *a,int s,int e)
{
   int mid=(s+e)/2;
   int i=s;
   int j=mid+1;
   int k=s;

   int temp[1000];
   int cnt=0;

   while(i<=mid and j<=e)
   {
       if(a[i]<=a[j])
       {
           temp[k]=a[i];
           k++;
           i++;
       }
       else                          //if first half array contain large element then all other next element are also larger than 2nd array
       {
           temp[k++]=a[j++];
           cnt+=mid-i+1;
       }
   }

   //fill the array if some element are left in one of the array
   while(i<=mid)
        temp[k++]=a[i++];

   while(j<=e)
        temp[k++]=a[j++];

   for(int i=s;i<=e;++i)
        a[i]=temp[i];

    return cnt;
}

int inversion_count(int *arr,int s,int e)
{
    //base case
    if(s>=e)
        return 0;

    //merge sort
    int mid=(s+e)/2;
    int x=inversion_count(arr,s,mid);
    int y=inversion_count(arr,mid+1,e);
    int z=mergee(arr,s,e);

    return x+y+z;
}

int main()
{
    int c;
    int arr[]={1,5,2,6,3,0};
    int n=sizeof(arr)/sizeof(int);
    cout<<inversion_count(arr,0,n-1);

    return 0;
}
