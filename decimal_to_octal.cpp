#include<iostream>
using namespace std;

void dec_to_oct(int n)
{
   int oct[100];
   int i=0;
   while(n>0)
   {
       oct[i]=n%8;
       n=n/8;
       ++i;
   }

   for(int j=i-1;j>=n;--j)
   {
       cout<<oct[j];
   }
}

int main()
{
    int n;
    cin>>n;

    dec_to_oct(n);

  return 0;
}
