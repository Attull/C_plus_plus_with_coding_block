//given team names and their preferred placement find one ranklist with the minimal possible badness
//badness-the distance b/w their preferred place and their place in the ranklist

#include<iostream>
#include<string>
using namespace std;

int abs(int i,int j)
{
    if(i-j >0)
        return i-j;
    else
        return j-i;
}

int main()
{
    int arr[10000]={0};
    int n;                                  //no. of teams
    string name;
    int rank;

    cin>>n;

    for(int i=0;i<n;++i)
    {
        cin>>name>>rank;
        ++arr[rank];                        //count sort concept
    }

    int actual_rank=1;                     //ranking start form 1
    int sum=0;
    for(int i=1;i<n;++i)
    {
        while(arr[i])
        {
            sum+=abs(actual_rank,i);
            arr[i]--;
            actual_rank++;                 //now we calculate for next rank
        }
    }
    cout<<sum<<endl;
}
