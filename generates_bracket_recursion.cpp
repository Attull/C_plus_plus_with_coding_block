//generate balanced brackets using N pairs of round brackets

#include<iostream>
using namespace std;

void generate_brackets(char *out,int n,int idx,int open,int close)
{                                                                   //we use three variable open,close and idx, idx is used as an index
    //base case                                                     // open & close count no. of open bracket and close brackets till now
    if(idx==2*n)
    {
        out[idx]='\0';
        cout<<out<<endl;
        return;
    }

    //rec case
    if(open<n)
    {
        out[idx]='(';
        generate_brackets(out,n,idx+1,open+1,close);
    }
    if(close<open)
    {
        out[idx]=')';
        generate_brackets(out,n,idx+1,open,close+1);
    }
    return;
}

int main()
{
    int n;
    cin>>n;

    char out[1000];
    int idx=0;
    generate_brackets(out,n,idx,0,0);
    return 0;
}
