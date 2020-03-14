#include<iostream>
using namespace std;

void toi(int n,char src,char dest,char helper)
{
    //base case
    if(n==0)
    {
        return;
    }

    //recursive case
    //first case n-1 disks move from src to helper
    toi(n-1,src,helper,dest);
    cout<<"move "<<n<<" disk from "<<src<<" to "<<dest<<endl;
    toi(n-1,helper,dest,src);

}
int main()
{
    int n;
    cin>>n;
    toi(n,'A','C','B');
}
