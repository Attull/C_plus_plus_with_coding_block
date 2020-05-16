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

int find_knode1(node *&head,int k)
{
    int l=len(head);
    node *temp=head;
    while((l-k)!=0)
    {
        temp=temp->next;
        ++k;
    }
    return temp->val;
}


int find_knode2(node *&head,int k)
{
    node *slow=head;
    node *fast=head;
    while(k!=0)
    {
        fast=fast->next;
        --k;
    }
    while(fast!=NULL)
    {
     slow=slow->next;
     fast=fast->next;
    }
    return slow->val;
}

int main()
{
    node *head=NULL;
    build_list(head);
    print_list(head);

   cout<<find_knode1(head,2);
   cout<<endl<<find_knode2(head,3);
    return 0;
}
