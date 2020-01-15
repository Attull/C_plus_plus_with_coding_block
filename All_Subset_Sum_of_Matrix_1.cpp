#include <iostream>
using namespace std;
int sub_sum(int a[][2])
{
    int sum=0,summ;
    for(int li=0;li<2;++li)
      {
        for(int lj=0;lj<2;++lj)                   //this & above loop set top left value
         {
            for(int bi=li+1;bi<2;++bi)
            {
                 for(int bj=lj+1;bj<2;++bj)          //this & above loop set bottom right value
                 {
                     for(int i=li;i<=bi;++i)       //now we run the loop from top left value to bottom right value
                     {
                          for(int j=lj;j<=bj;++j)
                          {
                               sum+=a[i][j];        //calculate all subset sum of matrix
                          }
                     }

                 }
            }
         }
     }
   return sum;
}

int main()
{
    int a[][2]={{1,1},
                {1,1}};

    cout<<sub_sum(a);
}
