#include<iostream>
using namespace std;

class node
{
    public:
            int data;
            node *next;

            node(int val)
            {
                data=val;
            }
};

void insertion_at_beg(node *&head,int val)
{
    node *n=new node(val);
    n->next=head;
    head=n;
}

void build_list(node *&head)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        insertion_at_beg(head,data);
        cin>>data;
    }
}

void print_list(node*&head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

bool cycle_det(node *&head)
{
    node *a=head;
    node *b=head->next;

    while(b!=NULL && b->next!=NULL)
    {
        a=a->next;
        b=b->next->next;

        if(a==b)
            return true;
    }
    return false;
}

int main()
{
    node *head=NULL;
    build_list(head);
    print_list(head);
    cout<<cycle_det(head);
    return NULL;
}
