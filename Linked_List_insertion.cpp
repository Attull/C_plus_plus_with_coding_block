#include <iostream>
using namespace std;

class node
{
    public:
            int val;
            node *next;

            //constructor
            node(int data)
            {
                val=data;
                next=NULL;
            }

};

void InsertAtBeg(node *&head,int data)      //passing a pointer variable by reference
{
    node *n=new node(data);
    n->next=head;
    head=n;
}

void InsertAtTail(node *&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node *tail=head;

    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return ;
}

int len(node *head)
{
    int l=0;
    node *temp=head;
    while(temp!=NULL)
    {
        ++l;
        temp=temp->next;
    }
    return l;
}

void InsertAtMiddle(node *&head,int data,int pos)      //passing a pointer variable by reference
{
    if(head==NULL || pos==0)
        InsertAtBeg(head,data);
    else if(pos>len(head))
        InsertAtTail(head,data);
    else
    {
        int jump=1;
        node *temp=head;
        while(jump<=pos-1)
        {
            temp=temp->next;
            ++jump;
        }
        node *n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

void printNode(node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    node *head=NULL;
    InsertAtBeg(head,11);
    InsertAtBeg(head,12);
    InsertAtTail(head,10);
    InsertAtMiddle(head,3,2);
   // InsertAtTail(head,10);
    printNode(head);

    return 0;
}
