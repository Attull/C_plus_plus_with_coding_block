#include<iostream>
#include<string.h>
using namespace std;

void filter_str(int n,char str[])
{
    int j=0;
    while(n)
    {
        int last_bit=(n&1);
        if(last_bit)
        {
            cout<<str[j];
        }
        j++;
        n=n>>1;
    }
}
void print_subset(char str[])
{
    int n=strlen(str);
    for(int i=0;i<(1<<n);++i)
    {
        filter_str(i,str);
        cout<<endl;
    }

}
int main()
{
    char str[]="abc";

    print_subset(str);

    return 0;
}
