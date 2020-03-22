#include<iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n)
{
    //we can check for col
    for(int row;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }

    //we can check for left diagonal
    int x=i;
    int y=j;

    while(x>=0 && y>=0)
    {
        if(board[x][y]==1){
            return false;
        }

        x--;
        y--;
    }
      //we can check for right diagonal
    x=i;
    y=j;

    while(x>=0 && y<n)
    {
        if(board[x][y]==1){
            return false;
        }

        x--;
        y++;
    }

    //it means position is safe
    return true;
}

bool solve_NQueen(int board[][10],int i,int n)
{
    //base case
    if(i==n)
    {   //we have successfully place all queens in a rows
         //print the board
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(board[i][j]==1)
                    cout<<"Q ";
                else
                    cout<<"_ ";
            }
            cout<<endl;
        }

        cout<<endl;
        return false;
    }

    //recursive case
    //try to place the queen in the current row and call on the remaining part which will be solved by recursion
    for(int j=0;j<n;++j)
    {   //check if i,j position is safe or not
        if(isSafe(board,i,j,n))
        {
            board[i][j]=1;                  //place the queen ,if position is safe

            bool nextQueenRakhPaye =solve_NQueen(board,i+1,n);
            if(nextQueenRakhPaye){
                return true;
            }

            board[i][j]=0;
        }
    }
    return false;

}
int main()
{
    int n;
    cin>>n;

    int board[10][10]={0};

    solve_NQueen(board,0,n);
    return 0;

}
