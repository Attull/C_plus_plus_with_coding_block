
#include <iostream>
#include <cstring>
#include<algorithm>                    //include sort function
using namespace std;
int main()
{
    string s1("string 1");             //method 1 to initialize string
    cout<<s1<<endl;

    string s2="string 2";              //method 2 to initialize string
    cout<<s2<<endl;

    string s3;
    getline(cin,s3);                  //method 3 to initialize string
    cout<<s3;


    string s4[]={"zebra ","atul ","rahul ","lalit "};
    for(int i=0;i<4;++i)
        cout<<s4[i];

    sort(s4,s4+4);                    //sort string
    for(int i=0;i<4;++i)
        cout<<s4[i];

}
