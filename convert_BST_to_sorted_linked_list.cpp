#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class node
{
    public:
            int val;
            node *left;
            node *right;

            node(int data)
            {
                val=data;
                left=NULL;
                right=NULL;
            }
};

node *insert_in_bst(node *root,int data)
{
    node *temp=new node(data);

    //base case
    if(root==NULL)
        return temp;

    //rec case
    if(data<=root->val)                                      //if data is less then current root value then insert it in left subtree
        root->left=insert_in_bst(root->left,data);
    else
        root->right=insert_in_bst(root->right,data);

}

void bfs(node *root)                    //using queue
{
        queue <node*> q;
        q.push(root);                              //first push node
        q.push(NULL);                              //then push NULL

        while(!q.empty())
        {
            node *f=q.front();
            if(f==NULL)                            //if NULL encounter
            {
                cout<<endl;                       //move to next line
                q.pop();                          //remove NULL from queue
                if(!q.empty())
                {                                 //if queue is not empty then push NULL in queue i.e.
                    q.push(NULL);                 // if queue is 6,7 then it become 6,7,NULL
                }
            }
            else                                  //if element is encounter
             {
                cout<<f->val<<",";               //print it
                q.pop();                         //then pop it

                if(f->left)                      //if it has left child then push it in queue
                {
                    q.push(f->left);
                }
                if(f->right)                     //if it has right child then push it in queue
                {
                    q.push(f->right);
                }
             }
        }
        return ;
}

node *build()
{
    int d;
    cin>>d;

    node *root=NULL;

    while(d!=-1)
    {
        root=insert_in_bst(root,d);
        cin>>d;
    }

    return root;
}

class linkedlist
{
    public:
            node *head;
            node *tail;
};

linkedlist flatten(node *root)
{
    linkedlist l;

    if(root==NULL)
    {
        l.head=l.tail=NULL;
        return l;
    }

    //leaf node
    if(root->left==NULL && root->right==NULL)
    {
        l.head=root;
        l.tail=root;
        return l;
    }
    //leaf is not null
    if(root->left!=NULL && root->right==NULL)
    {
        linkedlist leftll=flatten(root->left);
        leftll.tail->right=root;

        l.head=leftll.head;
        l.tail=root;
        return l;
    }

    if(root->left==NULL && root->right!=NULL)
    {
        linkedlist rightll=flatten(root->right);
        root->right=rightll.head;

        l.head=root;
        l.tail=rightll.tail;
        return l;
    }

    //both sides are not NULL
    if(root->left!=NULL && root->right!=NULL)
    {
        linkedlist leftll=flatten(root->left);
        linkedlist rightll=flatten(root->right);

        leftll.tail->right=root;
        root->right=rightll.head;

        l.head=leftll.head;
        l.tail=rightll.tail;
        return l;
    }

}
int main()
{
    node *root=build();

    bfs(root);
    cout<<endl;

    linkedlist ll=flatten(root);
    node *temp=ll.head;

    while(temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp=temp->right;
    }
    cout<<endl;


    return 0;
}

