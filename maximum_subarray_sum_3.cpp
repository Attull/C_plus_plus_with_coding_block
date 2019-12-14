//maximum subarray sum with O(n) time complexity (kadane algorithm)

#include <iostream>
using namespace std;
int main()
{
    int n,arr[1000];

    cout<<"enter the size of an array \n";
    cin>>n;

    cout<<"enter array element values \n";

    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }

    cout<<"array contain\t";
    for(int i=0;i<n;++i)
        cout<<arr[i]<<",";

    int maxx=0,sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];                         //calculating sum by adding one by one each element
        if(sum<0)                            //then check if sum is negative then make sum=0
            sum=0;

        maxx=max(maxx,sum);                   //using inbuild function to find maximum of maxx & sum
    }

    cout<<"\n maximum subarray sum is :\n"<<maxx;
    return 0;
}
