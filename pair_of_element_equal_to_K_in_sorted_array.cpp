//given a sorted array,find pair of elements that sum to K(given)

#include<iostream>
using namespace std;

int main()
{
    int n,target_sum;

    n=5;
    int a[]={2,3,5,7,13};
    target_sum=10;

    int i=0,j=n-1;
    while(i<j)                              //we use the concept of binary search using two pointer one point to start and other to last
    {
        int sum=a[i]+a[j];
        if(sum==target_sum)
        {
            cout<<a[i]<<" "<<a[j]<<endl;
            ++i;
            --j;
        }
        else if(sum<target_sum)            //if current sun <target sum then we move pointer i forword
            ++i;
        else if(sum>target_sum)
            ++j;
    }
    return 0;
}
