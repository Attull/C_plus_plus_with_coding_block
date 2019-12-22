//maximum subarray sum with O(n^3) time complexity

#include <iostream>
using namespace std;
int main()
{
    int n,arr[1000];
    cout<<"enter the size of an array \n";
    cin>>n;

    cout<<"enter array element values \n";
    for(int i=0;i<n;++i)
        cin>>arr[i];

    cout<<"array contain\t";
    for(int i=0;i<n;++i)
        cout<<arr[i]<<",";

    int maxx=0,sum=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sum=0;
            for(int k=i;k<=j;++k)
            {
                sum+=arr[k];                         //calculating each subarray sum one by one
            }
            if(maxx<=sum)                            //then compare brute-forcely each possible sum one by one to get maximum subarray sum
            maxx=sum;
        }
    }
    cout<<"\n maximum subarray is :\n"<<maxx;
    return 0;
}
