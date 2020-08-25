//Check if a linked list is a palindrome.( Boolean return type )

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

void InsertAtTail(node *&head,int data)
{
    node *n=new node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node *tail=head;

    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=n;
    return;
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

bool check_palin(node *&head)
{
    node *start=head;
    node *last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    while(start<=last)
    {
        if(start->val!=last->val)
            return false;

        start=start->next;
        last=last->next;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    node *head=NULL;

    for(int i=0;i<n;++i)
    {
        int data;
        cin>>data;
        InsertAtTail(head,data);
    }

    print_list(head);

    if(check_palin(head))
        cout<<"true";
    else
        cout<<"false";

    return 0;
}
