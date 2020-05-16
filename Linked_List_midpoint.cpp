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

insertion_at_beg(node *&head,int data)
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

int midpoint(node *&head)                  //using two pointer slow and fast to find midpoint
{
    node *slow=head;
    node *fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;                    //slow take 1 jump
        fast=fast->next->next;              //fast take 2 jump
    }
    return slow->val;
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

int main()
{
    node *head=NULL;
    build_list(head);
    print_list(head);
    cout<<midpoint(head);
    return 0;
}
