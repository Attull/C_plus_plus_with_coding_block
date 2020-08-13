//given n friends who want to go to a party on bikes
//each guy can go single or as a couple
//find number of ways in which n guy can go to party

#include<iostream>
using namespace std;

int frd_pair(int n)
{
    if(n==0 || n==1)
        return 1;

    if(n==2)
        return 2;

    int ans=0;

    ans=ans + 1*frd_pair(n-1)+(n-1)*frd_pair(n-2);          //two possible case 1. if he goes single or if he goes as couple then
                                                            //he has (n-1)C1 no. of ways of choosing his partner
    return ans;
}
int main()
{
    int n;                  //number of friends
    cin>>n;

    cout<<frd_pair(n);
}
