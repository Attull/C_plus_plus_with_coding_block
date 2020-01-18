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

    int *p=a;                       //pointer assign to first element of array
    int *r=&a[n-1];                 //pointer assign to last element of array

    for(int i=0;i<n;++i)
    {
        int s=(*p)+(*r);            //storing sum
        if((*p)!=(*r))
        {

          if(s==target)
             {
                cout<<(*p)<<" and "<<(*r)<<endl;
                *(++p);
             }
            else if(s>target)
              {
                  *(--r);
              }
            else
               {
                 *(++p);
               }
        }
     }

}

