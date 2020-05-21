#include<iostream>
#include<stack>
using namespace std;

bool check(string str)
{
    stack <char> s;

    for(int i=0;i<str.size();++i)
    {
        char curchar=str[i];
        if(curchar=='(')
            s.push(curchar);
        else if(curchar==')')
        {
            if(s.empty() || s.top()!='(')           //if next char is '(' and then stack top or check whether it is empty or not
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}
int main()
{
    string exp;
    cin>>exp;

    bool isvalid=check(exp);
    cout<<isvalid;
    return 0;
}
