#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,a[1000];
    cout<<"enter number of element \n";
    cin>>n;

    cout<<"enter array value \n";
    for(int i=0;i<n;++i)
        cin>>a[i];

    int target;
    cout<<"target sum value :\n";
    cin>>target;

    int sum,temp;
    sort(a,a+n);                    //sort the array

       int p=0;                       //pointer assign to first element of array
    int r=n-1;                 //pointer assign to last element of array

    for(int i=0;i<n;++i)
    {
        int s=a[p]+a[r];            //storing sum
        if(p!=r)
        {
          if(s==target)
             {
                cout<<a[p]<<" and "<<a[r]<<endl;
                 ++p;
             }
            else if(s>target)
              {
                  --r;
              }
            else
               {
                 ++p;
               }
        }
     }

}

