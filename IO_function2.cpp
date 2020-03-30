//getline() and write()
//getline() is a input function and reads a line of text end with new-line character
//cin.getline(line,size)

#include<iostream>
using namespace std;
int main()
{
    char string1[20]={0},string2[25]={0};
    cout<<"enter string 1 \t";
    cin.getline(string1,20);

    cout<<"enter string 2 \t";
    cin.getline(string2,25);

    cout<<endl;
    cout<<"string 1 is \t";
    cout.write(string1,20);

    cout<<endl;
    cout<<"string 2 is \t";
    cout.write(string2,5);
}
