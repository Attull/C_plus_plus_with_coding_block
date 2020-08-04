#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string extract_string_at_key(string str,char key)
{
    char *s=strtok((char *)str.c_str()," ");        //c_str() is returns a pointer to an array that contains a
    while(key>1)                                    //null-terminated sequence of characters
    {
        s=strtok(NULL," ");
        key--;
    }
    return (string)s;
}

int string_to_int(string s)
{
    int ans=0;
    int p=1;
    for(int i=s.length();i>=0;--i)
    {
        ans+=((s[i]-'0')*p);
        p=p*10;
    }
    return ans;
}

bool numeric_compare(pair <string,string> s1,pair<string,string> s2)
{
    string key1,key2;
    key1=s1.second;
    key2=s2.second;

    return string_to_int(key1) < string_to_int(key2);

}

bool lexi_compare(pair <string,string> s1,pair<string,string> s2)
{
    string key1,key2;
    key1=s1.second;
    key2=s2.second;

    return key1 < key2 ;

}

int main()
{
    int n;                                           //number of strings
    cout<<"enter no of string \n";
    cin>>n;
    cin.get();                                       //to ignore '\n'

    cout<<"enter string value \n";
    string a[100];
    for(int i=0;i<n;++i)
        getline(cin,a[i]);

    int key;
    string rev,comp_type;                                      //position for which comparison has to be done
    cin>>key;
    cin>>rev;
    cin>>comp_type;

    //to get key position value of each string we use pair container

    pair<string, string> strpair[100];

    for(int i=0;i<n;++i)
    {
        strpair[i].first=a[i];
        strpair[i].second=extract_string_at_key(a[i],key);
    }

    //sorting (numeric or lexicographically )
    if(comp_type=="numeric")
        sort(strpair,strpair+n,numeric_compare);
    else
        sort(strpair,strpair+n,lexi_compare);

    //reversal
    if(rev=="true")
    {
        for(int i=0;i<n/2;++i)
            swap(strpair[i],strpair[n-i-1]);
    }

    //print
    for(int i=0;i<n;++i)
        cout<<strpair[i].first<<endl;

    return 0;

}
