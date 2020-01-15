#include<iostream>
#define R 4
#define C 5
using namespace std;

int pre[R][C];

void prefix_sum(int a[][C],int p,int q,int x,int y)
{
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
          if(i>0 && j>0)
          {
              pre[i][j]=a[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
          }
          else if(i==0 && j>0)                           //for first row
          {
              pre[i][j]=a[i][j]+pre[i][j-1];
          }
          else if(i>0 && j==0)                           //for first column
          {
              pre[i][j]=a[i][j]+pre[i-1][j];
          }
          else
          {
              pre[i][j]=a[i][j];
          }
        }
    }

    for(int i=0;i<R;++i)                //display prefix sum matrix
    {
        for(int j=0;j<C;++j)
        {
            cout<<pre[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum=0;
    sum=pre[x][y]-pre[p-1][y]-pre[x][q-1]+pre[p-1][q-1];
    cout<<endl<<"subset sum of b/w index (1,1) & (3,4)  :"<<sum;
}

int main()
{
    int a[][C]={{1,1,1,1,1},
                {1,1,1,1,1},
                {1,1,1,1,1},
                {1,1,1,1,1}};

    cout<<"prefix matrix \n";
    prefix_sum(a,1,1,3,4);        //pass array and top left index & bottom right index whose subset has to be calculated
}
