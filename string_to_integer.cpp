#include<iostream>
#include<string>
using namespace std;

int conv(char s,int n)
{
    if(n==0)
        return 0;

    int digit=s[n-1]-'0';               //change last char to int
    int small_ans=conv(s,n-1);          //we recursively call by reducing size such that we get first position element

    return small_ans*10+digit;          //ex 0*10+1  ,return 1
                                        //   1*10+2  ,return 12
                                        //   12*10+3 ,return 123
}

int main()
{
    string s="atul is cool";
    int n=s.length();
    int a=conv(s,n);

    cout<<a;
}
