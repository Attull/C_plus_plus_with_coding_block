#include<iostream>
#include<algorithm>
using namespace std;

void selection_sort(int a[],int n)
{
    int min_idx;
    for(int i=0;i<n-1;++i)
     {
         min_idx=i;
        for(int j=i+1;j<n;++j)
        {
            if(a[min_idx]>a[j])
            {
                min_idx=j;                        // min_idx store the position of minimum value in array
            }
        }
        swap(a[i],a[min_idx]);
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

    selection_sort(a,n);

    return 0;
}
