//if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings
//and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string a,string b)
{
	if(a.find(b)==0 || b.find(a)==0)          //Finds the element in the given range of numbers. Returns an iterator to the first element in
		return a.length()> b.length();        //the range [first,last) that compares equal to val. If no such element is found, the function
                                              //returns last.The default value of startin position is 0,we can change it by find(a,b,pos)
	return a<b;
}
int main()
{
	int n;
	cin>>n;
    cin.get();
	string s[1000];

	for(int i=0;i<n;++i)
	{
		getline(cin,s[i]);
	}

	sort(s,s+n,compare);

	for(int i=0;i<n;++i)
		cout<<s[i]<<endl;

	return 0;
}
