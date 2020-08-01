#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class stack{
        queue<T> q1,q2;
    public:
        void push(T x)
        {
            q1.push(x);
        }
        void pop()
        {
            //remove the last added element from q1
            //for that first we have to move first n-1 element in q2
            //interchange the names of q1 and q2

            if(q1.empty())
            {
                return;
            }

            while(q1.size()>1)
            {
                T element=q1.front();
                q2.push(element);
                q1.pop();
            }
            //remove last element
            q1.pop();
            //then swap the names of q1 and q2
            swap(q1,q2);

        }
        int top()
        {
            while(q1.size()>1)
            {
                T element=q1.front();
                q2.push(element);
                q1.pop();
            }

            T element=q1.front();
            q1.pop();
            q2.push(element);

            swap(q1,q2);
            return element;
        }

        bool isempty()
        {
            return (q1.size()+q2.size()==0);
        }
};

int main()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
  //  s.pop();
    while(!s.isempty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
