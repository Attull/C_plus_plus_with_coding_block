#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int temp=2*n;                       //total number of columns
    int k=n;
    for(int j=1;j<temp;++j)
    {
        for(int i=1;i<k;++i)
                cout<<" ";

        --k;

        if(j==1 || j==n)                  //for first row and last row
         {
            for(int i=1;i<=n;++i)
                cout<<"*";
         }
        else                              //for the remaining rows
        {
            for(int i=1;i<=n;++i)
             {
                if(i==1 || i==n)
                    cout<<"*";
                else
                    cout<<" ";
             }
        }
        cout<<endl;
        --temp;
    }
}
