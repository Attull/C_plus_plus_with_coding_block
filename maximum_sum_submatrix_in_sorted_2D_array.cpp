#include <iostream>
#define R 3
#define C 3
using namespace std;

void suffix_sum(int a[][C])
{
    int s[R][C];

    s[R-1][C-1]=a[R-1][C-1];

    for(int i=R-2;i>=0;--i)
        s[i][C-1]=s[i+1][C-1]+a[i][C-1];

    for(int j=C-2;j>=0;--j)
        s[R-1][j]=s[R-1][j+1]+a[R-1][j];

    for(int i=R-2;i>=0;--i)
        for(int j=C-2;j>=0;--j)
            s[i][j]=a[i][j]+s[i+1][j]+s[i][j+1]-s[i+1][j+1];

    cout<<"suffix sum matrix "<<endl;
    for(int i=0;i<R;++i)
      {
        for(int j=0;j<C;++j)
         {
             cout<<s[i][j]<<" ";
         }
         cout<<endl;
      }

      cout<<"maximum submatrix sum value in 2D sorted matrix is :"<<"\t";
      int result=INT_MIN;
      for(int i=0;i<R;++i)
      {
        for(int j=0;j<C;++j)
         {
             result=max(result,s[i][j]);
         }
      }
      cout<<result;
}

int main()
{
    int a[][C]={{5,-4,-1},
                {-3,2,4},
                {2,5,8}
                };

    suffix_sum(a);
}
