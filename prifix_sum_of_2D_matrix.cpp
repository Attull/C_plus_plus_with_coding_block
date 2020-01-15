#include <iostream>
#define R 3
#define C 3
using namespace std;

void sub_sum(int a[][C])
{
    int sum=0;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            sum+=a[i][j]*(i+1)*(j+1)*(R-i)*(C-j);

    cout<<sum;
}

int main()
{
    int a[][C]={{1,1,1},
                {1,1,1},
                {1,1,1}
                //{1,1,1,1,1}
                };

    sub_sum(a);
}
