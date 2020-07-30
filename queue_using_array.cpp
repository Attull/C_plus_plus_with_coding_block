#include<iostream>
using namespace std;

class queue{

    int *arr;
    int f,r,cs,ms;           //cs:current size , ms:maximum size

    public:

    queue(int ds)          //ds:default size
    {
        arr=new int[ds];
        cs=0;
        ms=ds;
        f=0;
        r=0;
    }
    ~queue()
    {

    }

    void enqueue(int data)
    {
        //check queue is full or not
        if(ms==r)
        {
            cout<<"queue is full \n";
            return;
        }
        else
        {
            arr[r]=data;
            r++;
        }
        return;
    }

    void dequeue()
    {
        if(f==r)
        {
            cout<<"queue is empty \n";
        }
        else
        {
            for(int i=0;i<r-1;++i)
            {
                arr[i]=arr[i+1];
            }
            r--;
        }
        return;
    }

    void display()
    {
        if(f==r)
        {
            cout<<"queue is empty \n";
            return;
        }

        for(int i=f;i<r;++i)
            cout<<" "<<arr[i];

        return;
    }
};


int main()
{
    queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    //q.display();

    q.dequeue();
    q.enqueue(12);
    q.dequeue();
    q.enqueue(33);

    q.display();

    return 0;
}
