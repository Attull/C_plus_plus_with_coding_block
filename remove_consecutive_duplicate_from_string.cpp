#include<iostream>
#include<string.h>
using namespace std;

void remove_duplicate(char a[])
{
    int len=strlen(a);
    if(len==1 || len==0)           //if string is of 0 or 1 length
        return ;

    int prev=0;
    for(int cur=1;cur<len;++cur)   //cur variable to iterate through string
    {
        if(a[cur]!=a[prev])        // c c o  if cur is at o and prev is at first c then move prev one step and replace a[prev] and a[cur]
         {
             prev++;
             a[prev]=a[cur];
         }
    }
    a[prev+1]='\0';               //to end the string after removing duplicate
}

int main()
{
    char a[1000];
    cin.getline(a,1000);

    remove_duplicate(a);

    cout<<a;
}
