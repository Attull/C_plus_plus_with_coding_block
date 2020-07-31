#include<iostream>
#include<list>            //inbuild linked list header file
using namespace std;

class Queue{
    int cs;
    list <int> l;

    public:

    Queue(){
        cs=0;
    }

    bool isempty()
        return cs==0;

    void push(int data)
    {
        l.push_back(data);
        cs=cs+1;
    }

    void pop()
    {
        if(!isempty())
        {
            cs--;
            l.pop_front();
        }
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.isempty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
