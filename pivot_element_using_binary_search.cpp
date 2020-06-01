//it gives the position of that position from where array is rotated

#include<iostream>
#include<algorithm>
using namespace std;

int pivot(int a[],int beg,int last)
{
    int mid;

    while(beg<=last)
    {
        mid=(beg+last)/2;

        if(mid>beg && a[mid]<a[mid-1])               // eg  4 5 1 2 3
        {
            return mid-1;
        }
        else if(mid<last && a[mid]>a[mid+1])         // eg 3 4 5 1 2
        {
            return mid;
        }
        else
        {
            if(a[mid]<=a[beg])                       //eg 5 1 2 3 4
            {
                last=mid-1;
            }
            else                                     //eg 2 3 4 5 1
            {
                beg=mid+1;
            }
        }
    }
}

int main()
{

    int n,a[1000];
    cout<<"enter the size of array \n";
    cin>>n;

    cout<<"enter array element \n";
    for(int i=0;i<n;++i)
       cin>>a[i];

    int index=pivot(a,0,n-1);

    if(index<0)
        cout<<"not found\n";
    else
        cout<<"Pivot element is found at index "<<index;

    return 0;
}
