#include<iostream>
#include<vector>
using namespace std;

vector<int> prime_sieve(int *p,int n)
{
    p[0]=p[1]=0;
    p[2]=1;

    for(int i=3;i<=n;i=i+2)                  //assign 1 to all odd numbers
        p[i]=1;

    for(int i=3;i*i<=n;++i)
    {
        if(p[i]==1)                          //if a number is prime then all its multiple can not be prime
        {                                    //so we assign 0 to all its multiple
            for(int j=i*i;j<=n;j=j+i)
                p[j]=0;
        }
    }

    vector<int> primes;                      //declare vector of int type to store all prime numbers
    primes.push_back(2);

    for(int i=3;i<=n;i=i+2)
    {
        if(p[i])
        {
            primes.push_back(i);
        }
    }
    return primes;                              //vector contain all prime number is return back
}

vector<int> factorize(int m,vector<int> &prime)   //m is given number whose prime factorize we have to find
{
    vector<int> factors;
    factors.clear();

    int i=0;
    int p=prime[0];                            //p store first prime number

    while(p*p<=m)                              // run loop for only sqrt(m)
    {
        if(m%p==0)
        {
            factors.push_back(p);
            m=m/p;
        }
        i++;                                   //check for next prime number
        p=prime[i];
    }
    if(m!=1)
        factors.push_back(m);

    return factors;
}

int main()
{
    int p[10000]={0};                                 //declare array and it is pass to prime_sieve function to mark all prime numbers
    vector<int> prime=prime_sieve(p,10000);

    int no;
    cin>>no;

    vector<int> factors=factorize(no,prime);         //finding prime factor and store it in vector "factors"

    for(auto f1:factors)
        cout<<f<<" "<<endl;

    return 0;
}
