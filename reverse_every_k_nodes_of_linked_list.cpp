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

node *reverse_list(node *&head,int k)
{
    node *prev=NULL;
    node *cur=head;
    node *nex;
    int cnt=0;

    while(cur!=NULL && cnt<k)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
        cnt++;
    }

    if(nex!=NULL)                                //if after reversing k nodes the upcoming node is not NULL then it reverse next k elements
        head->next=reverse_list(nex,k);

    return prev;
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

int main()
{
    node *head=NULL;
    int n,k;                            //n is number of elements in list
                                        //k is number after which we have to reverse list
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        int data;
        cin>>data;
        InsertAtTail(head,data);
    }

    node *temp1=reverse_list(head,k);
    print(temp1);

    return 0;
}

