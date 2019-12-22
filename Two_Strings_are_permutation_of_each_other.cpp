#include <iostream>
#include<cstring>
using namespace std;

bool isPermutation(char *str1,char *str2)
{
    int l1=strlen(str1);
    int l2=strlen(str2);

    if(l1!=l2)                             //check their length
        return false;

    int freq[26]={0};                      //assuming char from a-z

    for(int i=0;i<=l1;++i)                 //iterate over l1(length of string 1
        freq[str1[i]-'a']++;               //count each character and store counting in freq array

    for(int i=0;i<=l2;++i)                 //iterate over l1(length of string 2
        freq[str2[i]-'a']--;

    for(int i=0;i<26;++i)                 //check if all frequencies are zero or not
    {
        if(freq[i]!=0)
            return false;
    }

    return true;
}

int main()
{
    char str1[100],str2[100];
    cout<<"String 1\n";
    cin>>str1;
    cout<<"String 2\n";
    cin>>str2;

    if(isPermutation(str1,str2))
        cout<<"Strings are permutation of each other";
    else
        cout<<"Strings are not a permutation of each other";

}
