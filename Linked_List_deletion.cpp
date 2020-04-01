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

void printNode(node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<endl;
}

void DeleteAtBeg(node *&head)
{
    if(head==NULL)
        return;

    node *temp=head;
    head=head->next;
    delete temp;
    return;
}

void DeleteAtTail(node *&head)
{
    node *prev=NULL;
    node *temp=head;

    while(temp->next!=NULL)
     {
         prev=temp;
         temp=temp->next;
     }
     delete temp;
     prev->next=NULL;
}

void DeleteAtMiddle(node *&head,int pos)
{
    if(head==NULL)
        return;
    else
    {
        node *prev=NULL;
        node *temp=head;
        int jump=1;
        while(jump<pos)
        {
             prev=temp;
             temp=temp->next;
             ++jump;
        }
        prev->next=temp->next;
        delete temp;
        return ;
    }
}

int main()
{
    node *head=NULL;
    InsertAtBeg(head,6);
    InsertAtBeg(head,5);
    InsertAtBeg(head,4);
    InsertAtBeg(head,3);
    InsertAtBeg(head,2);
    InsertAtBeg(head,1);

    printNode(head);
    DeleteAtMiddle(head,4);
    printNode(head);
    DeleteAtTail(head);
    printNode(head);
    return 0;
}
