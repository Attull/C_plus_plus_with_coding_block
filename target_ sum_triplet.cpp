#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,a[1000];
    cout<<"enter the number of element \n";
    cin>>n;

    cout<<"enter the array element \n";
    for(int i=0;i<n;++i)
        cin>>a[i];

    sort(a,a+n);
    int target;
    cout<<"enter target sum value \n";
    cin>>target;

    int sum=0;
    for(int i=0;i<n-2;++i)
     {
        int p=i+1;
        int q=n-1;
        while(p<q)
        {
            sum=a[p]+a[q]+a[i];
            if(sum==target)
            {
                cout<<a[i]<<", "<<a[p]<<" and "<<a[q]<<endl;
                ++p;
                --q;
            }
            else if(sum<target)
            {
                ++p;
            }
            else if(sum>target)
            {
                --q;
            }
        }
     }
}
