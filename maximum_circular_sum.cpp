#include<iostream>
#include<algorithm>
using namespace std;

int kadane(int a[],int n)
{
      int msum=0,tsum=0;
      for(int i=0;i<n;++i)
      {
          tsum+=a[i];
          msum=max(tsum,msum);
          if(tsum<0)
            tsum=0;
      }

     return msum;
}

int main()
{
    int t,n,a[1000];

    cout<<"number of test case \n";
    cin>>t;                    //'t' take number of test case

    cout<<"enter number of element \n";
    cin>>n;

    int csum=0;

    for(int i=0;i<t;++i)
    {

      for(int i=0;i<n;++i)
            cin>>a[i];

      for(int i=0;i<n;++i)             //calculate cummalative sum for array
            csum+=a[i];

      int msum=kadane(a,n);            //calculate maximum subset

      for(int i=0;i<n;++i)
            a[i]=-a[i];                //change the sign of array elements

      int nsum=kadane(a,n);           //now again use kadane algo to calculate sum i.e. sum for negative values

      int temp=csum-(-nsum);           //subtract nsum from total sum i.e removing negative element sum

      cout<<"maximum subarray sum is : \n";

      if(msum>temp)
        cout<<msum;
      else
        cout<<temp;

    }
 return 0;
}
