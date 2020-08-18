//Maximum length substring having all same characters after k changes

#include<iostream>
#include<string>
using namespace std;

int perfect_string(string s,int n,int k,char ch)
{
	int r=0,l=0;
	int cnt=0;
	int maxlen=1;

	while(r<n)
	{
		if(s[r]!=ch)
			cnt++;

		while(cnt>k)
		{
			if(s[l]!=ch)
				--cnt;

			++l;
		}

		maxlen=max(maxlen,r-l+1);
		r++;
	}
	return maxlen;
}

int answer(string s,int n,int k)
{
	int mlen=1;
    for (int i = 0; i < 26; ++i) {
	mlen=max(mlen,perfect_string(s,n,k,i+'a'));
	//mlen=max(mlen,perfect_string(s,n,k,'y'));
    }
	return mlen;
}
int main () {
	int k;
	cin>>k;
	cin.get();
	string s;

	getline(cin,s);

	int n=s.length();
	cout<<answer(s,n,k);
	return 0;
}
