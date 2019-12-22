//Rotate string by k character

#include <iostream>
#include<cstring>
using namespace std;

void rotate(char *arr,int k)
{
    int len=strlen(arr);               //calculate length of string

    while(len>=0)
    {
        arr[len+k]=arr[len];           //shifting array by k
        --len;
    }

    len=strlen(arr);
    int s=0;
    int l=len-k;

    while(l<len)                       //rotate value i.e we shift the last k value to front position
    {
        arr[s]=arr[l];
        ++s;
        ++l;
    }

    arr[len-k]='\0';

}
int main()
{
    char arr[100];
    int k;
    cout<<"Enter the string to rotate\n";
    cin.getline(arr,100);
    cout<<"By what value string have to rotate\n";
    cin>>k;

    rotate(arr,k);

    cout<<"Rotate string is \t";
    cout<<arr<<endl;

}

