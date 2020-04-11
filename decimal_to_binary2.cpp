#include<iostream>
using namespace std;

void dec_to_bin(int n)
{
   int bin[32];
   int i=0;
   while(n>0)
   {
       bin[i]=n%2;
       n=n/2;
       ++i;
   }

   for(int j=i-1;j>n;--j)
   {
       cout<<bin[j];
   }
}

int main()
{
    int n;
    cin>>n;

    dec_to_bin(n);

  return 0;
}
