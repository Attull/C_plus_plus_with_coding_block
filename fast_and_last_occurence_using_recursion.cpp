#include<iostream>
using namespace std;

int lastOcc(int *arr,int n,int key)
{
    if(n==0)
        return -1;

    int i=lastOcc(arr+1,n-1,key);
    if(i==-1)
    {
        if(arr[0]==key)
            return 0;
        else
            return -1;
    }
    return i+1;
}

int firstOcc(int *arr,int n,int key)
{
    if(n==0)
        return -1;

    if(arr[0]==key)
        return 0;

    int i=firstOcc(arr+1,n-1,key);
    if(i==-1)
        return -1;

    return i+1;

}

int main()
{
    int arr[]={1,2,3,4,3,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"enter the element to find its occurence\n";
    int key;
    cin>>key;

    cout<<"first occurrence of "<<key<<" is \t";
    cout<<firstOcc(arr,n,key)<<endl;

    cout<<"last occurrence of "<<key<<" is \t";
    cout<<lastOcc(arr,n,key);

    return 0;
}
