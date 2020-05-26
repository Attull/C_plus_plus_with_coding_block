#include<iostream>
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

void print(node *root)
{
    if(root==NULL)
        return ;

    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

node *balance_tree_from_array(int a[],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }

    int mid=(s+e)/2;

    node *root=new node(a[mid]);
    root->left=balance_tree_from_array(a,s,mid-1);
    root->right=balance_tree_from_array(a,mid+1,e);

    return root;
}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n=7;

    node *root=balance_tree_from_array(a,0,n-1);
    print(root);
    return 0;
}
