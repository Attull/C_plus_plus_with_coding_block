#include <iostream>
using namespace std;
int sub_sum(int a[][3])
{
    int sum=0,summ;
    for(int li=0;li<3;++li)
      {
        for(int lj=0;lj<3;++lj)                   //this & above loop set top left value
         {
            for(int bi=li;bi<3;++bi)
            {
                 for(int bj=lj;bj<3;++bj)          //this & above loop set bottom right value
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
    int a[][3]={{1,1,1},
                {1,1,1},
                {1,1,1} };

    cout<<sub_sum(a);
}
