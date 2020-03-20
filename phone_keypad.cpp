#include<iostream>
using namespace std;

char keypad[][10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};     //define 2d array to store alphaphet

void phone_keypad(char *in,char *out,int i,int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<",";
        return;
    }

    int digit=in[i]-'0';                    //change char input to integer

    if(digit==1 || digit==0)                //do nothing if we get digit 0 & 1
    {
        phone_keypad(in,out,i+1,j);
    }

    for(int k=0;keypad[digit][k]!='\0';++k)
    {
        out[j]=keypad[digit][k];
        phone_keypad(in,out,i+1,j+1);
    }
}

int main()
{
    char in[100];
    cin>>in;

    char out[100];

    phone_keypad(in,out,0,0);
    return 0;
}
