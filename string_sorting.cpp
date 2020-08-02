#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string a,string b)         //used to modify in sorting method
{
    if(a.length()==b.length())          // if length is equal then sort as lexicographically
        return a<b;

    return a.length()>b.length();
}


int main()
{
    int n;
    cin>>n;
    cin.get();

    string s[100];

    for(int i=0;i<n;++i)
        getline(cin,s[i]);

    sort(s,s+n,compare);

    for(int i=0;i<n;++i)
        cout<<s[i]<<endl;

}
