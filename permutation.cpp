#include<iostream>
using namespace std;

void permutation(char in[],int i)
{
    if(in[i]=='\0')
    {
        cout<<in<<" ";
        return;
    }

    for(int j=i;in[j]!='\0';++j)       //'i' is set position and 'j' is used for traversing
    {
        swap(in[i],in[j]);             //code before function is for downward direction
        permutation(in,i+1);
        swap(in[i],in[j]);             //code after function is for upward direction
    }
}
int main()
{
    char in[100];
    cin>>in;

    permutation(in,0);
    return 0;
}
