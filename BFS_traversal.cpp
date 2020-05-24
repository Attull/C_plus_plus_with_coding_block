#include<iostream>
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

node *build_tree()
{
    int data;
    cin>>data;

    while(data==-1)
    {
        return NULL;
    }

    node *root=new node(data);
    root->left=build_tree();
    root->right=build_tree();
    return root;
}

int height_of_tree(node *root)
{
    if(root==NULL)
        return 0;

    int ls=height_of_tree(root->left);
    int rs=height_of_tree(root->right);

    return 1+max(ls,rs);                     //1+maximum of left and right subtree
}

void BFS_traversal(node *root)               //using queue
{
        queue <node*> q;
        q.push(root);                        //first push node

        while(!q.empty())
        {
            node *f=q.front();
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
        return ;
}

int main()
{
    node *root=build_tree();
    cout<<"BFS traversal \n";
    BFS_traversal(root);
}
