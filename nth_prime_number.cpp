#include<iostream>
#include<vector>
using namespace std;

#define max_size 10000001    //change 1 :increasesd size
int temp[max_size]={0};      //change 2 took it outside


void is_prime(vector<int> &prime)
{

    for(int i=3;i<max_size;i=i+2)
    {
        temp[i]=1;
    }

    for(int i=3;i*i<max_size;++i)
    {
        if(temp[i]==1)
        {
            for(int j=i*i;j<max_size;j=j+i)
                temp[j]=0;
        }
    }

    prime.push_back(2);
    for(int i=3;i<max_size;++i)
    {
        if(temp[i])
            prime.push_back(i);
    }

    temp[0]=0;
    temp[1]=0;
    temp[2]=1;
   // return prime;
}
int main()
{
    int n;
    cin>>n;

    vector<int> prime;

    is_prime(prime);


    cout<<prime[n-1];

    return 0;
}
