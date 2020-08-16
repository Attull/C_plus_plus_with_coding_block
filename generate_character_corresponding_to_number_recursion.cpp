#include<iostream>
using namespace std;

void generate_string(char *in,char *out,int i,int j)
{
    //base case
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    //rec case
    //one digit at time
    int digit=in[i]-'0';                                //change char value to digit
    char ch=digit+'A'-1;                                //change digit back to char value
    out[j]=ch;                                          //and store it in output array
    generate_string(in,out,i+1,j+1);

    //two digit at time
    if(in[i+1]!='\0')
    {
        int sec_digit=in[i+1]-'0';
        int no=digit*10+sec_digit;                      //it give nest two digit number
        if(no<=26)
        {
            char ch=no+'A'-1;
            out[j]=ch;
            generate_string(in,out,i+2,j+1);
        }
    }
    return ;
}

int main()
{
    char arr[100];
    cin>>arr;

    char out[100];                               //to store output

    generate_string(arr,out,0,0);
    return 0;

}
