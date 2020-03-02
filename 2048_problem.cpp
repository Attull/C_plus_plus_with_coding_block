#include<iostream>
using namespace std;

string spelling[]={"zero","one","two","three","four","five","six","seven","eight","nine"};       //char spelling[][10]

void print_in_word(int num)
{
    if(num==0)
        return;
    else
    {
        print_in_word(num/10);
        cout<<spelling[num%10]<<" ";
    }
}
int main()
{
    int num;
    cin>>num;

    print_in_word(num);
}
