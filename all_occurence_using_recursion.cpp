
#include<iostream>
using namespace std;

void all_occ(int *a,int i,int n,int key)
{
    if(i==n)
        return;

    if(a[i]==key)
        cout<<a[i]<<" ";

    all_occ(a,i+1,n,key);
}

int main()
{
    int arr[]={1,2,3,4,3,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"enter the element to find its occurence\n";
    int key;
    cin>>key;

    cout<<"All occurrence of "<<key<<" is \t";
    all_occ(arr,0,n,key);

    return 0;
}
