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
                next=NULL;
            }
};

void insertion_at_beg(node *&head,int data)
{
    node *n=new node(data);
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

void print_list(node *&head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node *merge_list(node *a,node *b)
{
      node *c;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    else
    {
        if(a->val < b->val)
        {
            c=a;
            c->next=merge_list(a->next,b);
        }
        else
        {
            c=b;
            c->next=merge_list(a,b->next);
        }
    }
    return c;
}
int main()
{
    node *head1=NULL;
    node *head2=NULL;
    build_list(head1);
    print_list(head1);

    build_list(head2);
    print_list(head2);

    node *head=merge_list(head1,head2);
    print_list(head);
    return 0;
}
