#include<iostream>
#include<algorithm>
using namespace std;

void insertion_sort(int a[],int n)
{
    int j;
    int temp;
    for(int i=1;i<n;++i)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
     }

    cout<<"sorted array is \n";
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
}

int main()
{
    int n;
    int a[100000];

    cout<<"enter the number of element \n";
    cin>>n;

    cout<<"enter the array element \n";
    for(int j=0;j<n;++j)
        cin>>a[j];

    insertion_sort(a,n);

    return 0;
}
