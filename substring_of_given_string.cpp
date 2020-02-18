#include<iostream>
#include<string.h>
using namespace std;

//substring are continues but subset are not

void subString(char str[],int n)
{
    for(int i=1;i<=n;++i)          //first for loop provide size of substring that are going to be print after each iteration
    {
        for(int j=0;j<=n-i;++j)    //it set staring position
        {
            int temp=j+i-1;         //end position
            for(int k=j;k<=temp;++k)
                cout<<str[k];

            cout<<endl;
        }
    }

}
int main()
{
    char str[]="abcd";
    subString(str,strlen(str));
    return 0;
}
