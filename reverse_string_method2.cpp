//// C++ program to print reverse of a string

#include <iostream>
#include <cstring>
using namespace std;

void reverse(string str)                // Function to reverse a string
{
    int p=str.length();
    for(int i=0; i<p/2; ++i)
    {
        swap(str[i],str[p-i-1]);        //swaping starting and last values
    }
    cout<<str;
}

int main(void)
{
	string s;
	getline(cin,s);
	reverse(s);
	return 0;
}

