#include<iostream>
#include<cstring>
using namespace std;

//strtok() splits according to give delimiters
//it need to be call in a loop to get all tokens and return NULL when there is no token

int main()
{
    char s[100]="quarantine become boring now";

    char *ptr=strtok(s," ");              //so this create a new array where first element get stored and its address is return
    cout<<ptr<<endl;

    while(ptr!=NULL)
    {
        ptr=strtok(NULL," ");
        cout<<ptr<<endl;
    }

    return 0;
}
