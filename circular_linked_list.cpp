#include<iostream>
using namespace std;

class node
{
    public:
            int val;
            node *next;

            node(int data)
            {
                val=data;
            }
};

void push(node *&head,int data)
{
    node *n=new node(data);
    node *temp=head;
    n->next=head;
    if(head!=NULL)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
    else
    {
        n->next=n;
    }
    head=n;
}

void pop(node *&head)
{
    if(head==NULL)
        cout<<"list is empty \n";
    else if(head->next==head)                 //if only one element is present
    {
        head=NULL;
    }
    else
    {
        node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        head=head->next;
    }
}
void print(node *&head)
{
    node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<temp->val;
    cout<<endl;
}

void srch_ele(node *&head,int ele)
{
    node *temp=head;
    int flag=0;
    if(head==NULL)
        cout<<"element is not found \n";

    while(temp->next!=head)
    {
        if(temp->val==ele)
            flag=1;

        temp=temp->next;
    }
    if(flag==0)
        cout<<"element is not present \n";
    else
        cout<<"element is present \n";
}

int main()
{
    node *head=NULL;
    push(head,3);
    push(head,8);
    push(head,90);
    print(head);
    pop(head);
    print(head);
    srch_ele(head,90);

}
