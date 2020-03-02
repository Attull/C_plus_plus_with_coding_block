//Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1 tiles.
//A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.

#include<iostream>
using namespace std;
int cnt(int n)
{
    if(n==1 || n==2)
        return n;
    else
    {
        return cnt(n-1)+cnt(n-2);            //for "4 x n" =>  cnt(n-1)+cnt(n-2)
    }
}
int main() {
    int n;
    cin>>n;

    cout<<cnt(n);
}
