#include<iostream>
using namespace std;

void subsequence(char in[],char out[],int i,int j)          //subset or subsequence
{
    //base case
    if(in[i]=='\0')                //if we are at last position of input array
    {
        out[j]='\0';               //then place null at last position and print it
        cout<<out<<endl;
        return;
    }

    //rec case

    out[j]=in[i];                   //place current input element in output element
    subsequence(in,out,i+1,j+1);    //1. include current element

    subsequence(in,out,i+1,j);      //1. exclude current element

}
int main()
{
    char in[100];
    cin>>in;

    char out[100];

    subsequence(in,out,0,0);
    return 0;
}
