#include <iostream>
#define R 4
#define C 5
using namespace std;

void sub_sum(int a[][C])
{
    int sum=0;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
         {
            int x=(i+1)*(j+1);
            int y=(R-i)*(C-j);
            sum+=a[i][j]*x*y;        //final sum is a[][] * the no. of submatrix the cell will be present
         }

    cout<<sum;
}

int main()
{
    int a[][C]={{1,1,1,1,1},
                {1,1,1,1,1},
                {1,1,1,1,1},
                {1,1,1,1,1}
                };

    sub_sum(a);
}
