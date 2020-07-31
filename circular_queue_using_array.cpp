
#include<iostream>
using namespace std;

class Queue
{
    int *arr;
    int f,r,cs,ms;
    public:
            Queue(int ds=5)
            {
                arr=new int[ds];
                cs=0;
                ms=ds;
                f=0;
                r=ms-1;
            }
            bool full()
            {
                return cs==ms;
            }
            bool empty()
            {
                return cs==0;
            }
            void push(int data)
            {
                if(!full())
                {
                    r=(r+1)%ms;          //first find position of r where we have to insert
                    arr[r]=data;         //then insert it at that position
                    cs++;                //increse currrent size
                }
            }

            void pop()
            {
                if(!empty())
                {
                    f=(f+1)%ms;
                     cs--;
                }
            }

            int front()
            {
                return arr[f];
            }
            ~Queue()
            {
                if(arr!=NULL){
                    delete [] arr;
                    arr=NULL;
                }

            }
};

int main()
{
    Queue q;

    for(int i=1;i<=6;++i)
        q.push(i);

    q.pop();
    q.push(12);
    q.pop();
    q.push(33);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
