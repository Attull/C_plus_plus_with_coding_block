#include<iostream>
using namespace std;

int multi(int a,int b)
{
    if(b==0)
        return 0 ;
    else
    {
        return a+multi(a,--b);
    }

}
int main() {
    int a,b;
    cin>>a>>b;

    cout<<multi(a,b);
}
