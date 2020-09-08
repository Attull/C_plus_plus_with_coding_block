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

int max_val(node *root)
{
    node *temp=root;
    while(temp->left!=NULL)
        temp=temp->left;

    return temp->val;
}

int min_val(node *root)
{
    node *temp=root;
    while(temp->right!=NULL)
        temp=temp->right;

    return temp->val;
}

bool is_bst1(node* root)
{
    if(root==NULL)
        return true;

    if(root->left!=NULL && max_val(root)>root->val)
        return false;

    if(root->right!=NULL && min_val(root)<root->val)
        return false;

    if(!is_bst1(root->left) || !is_bst1(root->right))
        return false;

    return true;
}

bool is_bst2(node *root,int minv=INT_MIN ,int maxv=INT_MAX)
{
    if(root==NULL)
        return true;

    if(root->val >= minv && root->val <= maxv && is_bst2(root->left,minv,root->val) && is_bst2(root->right,root->val,maxv))
        return true;

    return false;
}

int main()
{
    node *root=build();

    bfs(root);
    cout<<endl;

    //cout<<is_bst1(root);
    cout<<is_bst2(root);

    return 0;
}
