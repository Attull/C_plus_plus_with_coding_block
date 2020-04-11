#include<iostream>
using namespace std;

void dec_to_bin(int n)
{
   int num=0,pow=1;
   while(n)
   {
        int last_bit=(1&n);        //find last bit
        num+=pow*last_bit;
        pow=pow*10;              //increase power by 10 each time
        n=n>>1;
   }
   cout<<num;
}
int main()
{
    int n;
    cin>>n;

    dec_to_bin(n);

  return 0;
}
