#include <iostream>
#include<cstdlib>
using namespace std;

void lsearch(int arr[],int s,int n)
{
    int flag=0;
    for(int i=0;i<n;++i)
    {
        if(arr[i]==s)
            flag=1;
    }
    if(flag==1)
        cout<<"\t element is found\n";
    else
        cout<<"\t element not found\n";
}

void bsearch(int arr[],int s,int n)
{
    int left=0;
    int right=n-1;
    int mid,flag=0;

    while(left<=right)
    {
        mid =(left+right)/2;
        if(arr[mid]==s)
        {
            flag=1;
            break;
        }
        else if(arr[mid]>s)
            right=mid-1;
        else
            left=mid+1;
    }

    if(flag==1)
        cout<<"\t element is found\n";
    else
        cout<<"\t element not found\n";
}
int main()
{
    int n;
    cout<<"number of element in array \t";
    cin>>n;

    int arr[n];
    cout<<"enter the array's element \n";
    for(int i=0;i<n;++i)
       cin>>arr[i];

    int srch;
    cout<<"enter the element to search \t";
    cin>>srch;

    int ch;
    while(1)
    {
     cout<<"\nenter your choice \n1.Linear search \n2.Binary search \n3.EXIT\n";
     cin>>ch;
     switch(ch)
     {
         case 1:  lsearch(arr,srch,n);
                   break;
         case 2:  bsearch(arr,srch,n);
                   break;
         case 3:  exit(1);
     }
    }
}
