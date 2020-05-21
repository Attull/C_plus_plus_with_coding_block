#include<iostream>
#include<vector>
using namespace std;

template <typename T>     //The simple idea is to pass data type as a parameter so that we don’t need to write the
                         //same code for different data types.

class stack
{
    private:
            vector <T> v;

    public:
            void push(T data)
            {
                v.push_back(data);
            }

            bool empty()
            {
                return v.size()==0;
            }

            void pop()
            {
                if(!empty())
                {
                    v.pop_back();
                }
            }

            T top()
            {
                return v[v.size()-1];
            }
};

int main()
{
    stack <char> s;
    stack <int> s;                    //this make data type as a integer

    for(int i=65;i<=70;++i)
    {
        s.push(i);
    }

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
