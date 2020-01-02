#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void readmatrix(char a[][10],int r,int c)
{
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            cin>>a[i][j];
}

void printmatrix(char a[][10],int R,int C)
 {
     for(int i=0;i<R;++i)
     {
         for(int j=0;j<C;++j)
            cout<<a[i][j]<<" ";

      cout<<endl;
     }
 }


void rec(char a[][10],int r,int c)
{
        char p='O';
        int first_row=0,last_row=r-1;
        int first_col=0,last_col=c-1;

        while(first_row<=last_row && first_col <=last_col )
        {
          //if(first_row%2==0 && first_col%2==0)

               for(int i=first_row;i<=last_col;++i)
                {
                    a[first_row][i]=p;
                }
                ++first_row;

                for(int i=first_row;i<=last_row;++i)
                {
                    a[i][last_col]=p;
                }
                --last_col;

                if(first_row < last_row)
                {
                    for(int i=last_col;i>=first_col;--i)
                    {
                        a[last_row][i]=p;
                    }
                    --last_row;
                }

                if(first_col < last_col)
                {
                    for(int i=last_row;i>=first_row;--i)
                    {
                        a[i][first_col]=p;
                    }
                    ++first_col;
                }

                 p=(p=='O') ? 'X' :'O';              //flip the value of p for next iteration
          }

}

int main()
{
  char a[10][10];
  int row,col;
  cout<<"Enter number of rows & column \n";
  cin>> row>>col;

  cout<<"Enter the input for matrix \n";
  readmatrix(a,row,col);
  rec(a,row,col);

  cout<<"\nmatrix of alternate rectangle of 'o' and 'x' \n"<<endl;
  printmatrix(a,row,col);

  return 0;
}
