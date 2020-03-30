//cin.get() doesn't ignored white space but cin>> ignored white space and new-line character
//but both are single character function

#include<iostream>
using namespace std;
int main()
{
    int chcount=0;
    const char ent='\n';
    char ch;


    while(chcount!=8)

    {
        cin.get(ch);
        cout.put(ch);
        ++chcount;
    }
}
