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

bool SearchNode(node *&head,int ele)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->val==ele)
            return true;

        temp=temp->next;
    }
    return false;
}

bool SearchRecursive(node *&head,int ele)
{
    if(head==NULL)
        return false;

    if(head->val==ele)
        return true;
    else
        SearchRecursive(head->next,ele);
}

void BuildList(node *&head)          //take input until we enter -1
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        InsertAtBeg(head,data);
        cin>>data;
    }
}

int main()
{
    node *head=NULL;
    BuildList(head);
    printNode(head);

    if(SearchNode(head,15))
        cout<<"element is present \n";
    else
        cout<<"eleement is not present \n";

    if(SearchRecursive(head,4))
        cout<<"element is present \n";
    else
        cout<<"eleement is not present \n";

    return 0;
}
