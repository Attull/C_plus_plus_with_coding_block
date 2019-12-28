#include<iostream>
#include<cstring>

using namespace std;
int main()
{

    char a[10][100];
    int n;
    cout<<"enter number of strings you want to insert \n";
    cin>>n;

    for(int i=0;i<n;++i)
        cin.getline(a[i],100);

    char key[100];
    cout<<"enter the string to search \n";
    cin.getline(key,100);

    int i;
    for(i=0;i<n;++i)
    {
        if(strcmp(a[i],key)==0)                                   //we use inbuild function "strcmp" to compare
        {
            cout<<"string is found at index : "<<i;
            break;
        }
    }

    if(i==n)
        cout<<" string is not found ";

    return 0;

}
