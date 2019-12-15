// Program to print reverse of a string

#include <iostream>
#include <cstring>
using namespace std;

void reverse(string str)                // Function to reverse a string
{
    int p=str.length();               //finding length of string
    for (int i=p-1; i>=0; i--)
        cout << str[i];
}

int main(void)
{
	string s;
	getline(cin,s);                  //take input from user
	reverse(s);
	return 0;
}

