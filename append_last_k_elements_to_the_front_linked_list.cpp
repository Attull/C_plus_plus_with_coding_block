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


void print(node *&head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node *append_list(node *&head,int n,int k)
{
    node *temp1=head;
    node *prev=NULL;
    for(int i=0;i<n-k;++i)
    {
        prev=temp1;
        temp1=temp1->next;
    }
    prev->next=NULL;

    node *temp2=temp1;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=head;
    head=temp1;

    return head;
}

int main()
{
    node *head=NULL;
    int n,k;                            //n is number of elements in list

    cin>>n;
    for(int i=0;i<n;++i)
    {
        int data;
        cin>>data;
        InsertAtTail(head,data);
    }

    cin>>k;
	k=k%n;                               //becoz k can be larger than n
	if(k==0)
		print(head);
	else
    {
			node *temp=append_list(head,n,k);
			print(temp);
	}

    return 0;
}

