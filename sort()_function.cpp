#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool compare(string a,string b)           // it is used to make change in sort() function work i.e sort as per length or sort in descending order
{
    if(a.length() == b.length())
    {
        return a>b;                       // for descending order
    }
    else
     {
         return a.length() < b.length();
     }
}

int main()
{
    string a[5];

    for(int i=0;i<5;++i)
        getline(cin,a[i]);

    sort(a,a+5,compare);               //sort() is in build function used for sorting (by default ascending order)

    for(int i=0;i<5;++i)
        cout<<a[i]<<" ";

	return 0;
}
