#include<iostream>
#include<cmath>
using namespace std;

void ganesha_pattern(int row,int col)
 {
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            //for upper part
            if(i<row/2)
            {
                if(j<col/2)
                {
                    if(j==0)
                    {
                        cout<<"*";
                    }
                    else
                        cout<<" ";
                }
                else if(j==col/2)
                {
                    cout<<"*";
                }
                else if(i==0)
                {
                    cout<<"*";
                }
            }
            else if(i==row/2)
            {
                cout<<"*";
            }
            //for lower part
            else
            {
                if(j==col/2 || j==col-1)
                {
                    cout<<"*";
                }
                else if(i==row-1)
                {
                    if(j<=col/2 || j==col-1)
                    {
                        cout<<"*";
                    }
                    else
                    {
                        cout<<" ";
                    }
                }
                else
                    cout<<" ";
            }
        }
         cout<<endl;
    }
 }

int main()
{
    int n;
    cin>>n;             //take number of element as odd number
    cout<<endl;
    int row=n;
    int col=n;

    ganesha_pattern(row,col);
    return 0;
}
