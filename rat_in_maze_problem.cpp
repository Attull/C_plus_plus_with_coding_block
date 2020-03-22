#include<iostream>
using namespace std;

bool ratInMaze(char maze[][10],int sol[][10],int i,int j,int m,int n)
{
        if(i==m && j==n)
        {
            sol[i][j]=1;

            for(int i=0;i<=m;++i)
            {
                for(int j=0;j<=n;++j)
                {
                    cout<<sol[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;

            return true;
        }

    if(i>m || j>n)          //if rat comes outside grid
    {
        return false;
    }

    if(maze[i][j]=='X')      //if maze path is blocked
    {
        return false;
    }

    sol[i][j]=1;             //in the beginning assume there is path exist

    bool rightsucess=ratInMaze(maze,sol,i,j+1,m,n);
    bool downsuccess=ratInMaze(maze,sol,i+1,j,m,n);

    sol[i][j]=0;

    if(rightsucess || downsuccess)              //if there is path either on right side or on downside
    {
        return true;
    }
    return false;
}

int main()
{
    char maze[10][10]={
                        "0000",
                        "00X0",
                        "000X",
                        "0000",
    };

    int sol[10][10]={0};
    int m=4,n=4;

    bool res=ratInMaze(maze,sol,0,0,m-1,n-1);

    if(res==false)
        cout<<"path doesn't exist ";

    return 0;
}
