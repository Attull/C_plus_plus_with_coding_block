#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;

    int a[100000];
    cin>>n;

    for(int j=0;j<n;++j)
        cin>>a[j];

    int min_idx;
    for(int i=0;i<n-1;++i)
     {
         min_idx=i;
        for(int j=i+1;j<n-1;++j)
        {
            if(a[m]>a[j])
            {
                min_idx=j;                        // m store the position of minimum value in array
            }
        }
        swap(a[i],a[min_idx]);
     }

    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";


    return 0;
}
