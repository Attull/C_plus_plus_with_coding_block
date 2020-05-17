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

node *middle_point(node *&head)
{
    node *a=head;
    node *b=head->next;

    while(b!=NULL && b->next!=NULL)
    {
        a=a->next;
        b=b->next->next;
    }
    return a;
}

node *mergge(node *a,node *b)
{
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    node *c=NULL;
    if(a->data < b->data)
    {
        c=a;
        c->next=mergge(a->next,b);
    }
    else
    {
        c=b;
        c->next=mergge(a,b->next);
    }
}

node *merge_sort(node *&head)
{
    if(head==NULL || head->next==NULL)
        return head;

    node *mid=middle_point(head);
    node *a=head;
    node *b=mid->next;
    mid->next=NULL;

    a=merge_sort(a);
    b=merge_sort(b);

    node *c=mergge(a,b);
    return c;

}

int main()
{
    node *head=NULL;
    build_list(head);
    print_list(head);
    head=merge_sort(head);
    print_list(head);
    return NULL;
}
