#include<iostream>
#include<algorithm>               //for find();
using namespace std;

int main()
{
    int arr[]={2,5,7,12,90};
    int n=sizeof(arr)/sizeof(int);

    int key;
    cout<<"enter element to search \n";
    cin>>key;
    int *i=find(arr,arr+n,key);     //it return address of element if present
    int index=(i)-(arr);
    if(index>=n)
        cout<<"element is not found\n";
    else
        cout<<"element find at positon :"<<1+index;
}
