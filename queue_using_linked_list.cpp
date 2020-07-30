#include<iostream>
using namespace std;

struct node
{
    int ele;
    node *next;

    node(int data)
    {
        ele=data;
        next=NULL;
    }
};

class Queue
{
    node *front,*rear;
    public:
    Queue()
    {
        front=rear=NULL;
    }

    void enqueue(int data)
    {
        node *n=new node(data);

        if(rear==NULL)
        {
            front=rear=n;
            return;
        }
        rear->next=n;
        rear=n;
    }

    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"queue is empty\n";
            return;
        }
         node *temp=front;
         front=front->next;
         delete(temp);

    }

    void display()
    {
        node *temp=front;
        while(temp!=NULL)
        {
            cout<<"<--"<<temp->ele;
            temp=temp->next;
        }
        cout<<"\n";
    }
};

int main()
{
    Queue q;
    q.enqueue(11);
    q.enqueue(12);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
