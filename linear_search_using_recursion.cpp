#include<iostream>
using namespace std;

int lsearch(int arr[],int i,int key,int s)
{
   if(i==s)                                      //if index reached to last index value
        return -1;
   else if(arr[i]==key)                          //if element is found, print its index
        return i;
   else
   {
        lsearch(arr,i+1,key,s);                  //recursion call on the remaining call
   }
}
int main()
{
    int arr[]={1,2,3,4,5};
    int s=sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;

    cout<<lsearch(arr,0,key,s);
}
