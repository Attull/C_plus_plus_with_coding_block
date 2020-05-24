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

node *build_tree()
{
    int data;
    cin>>data;

    if(data==-1)
    {
        return NULL;
    }

    node *root=new node(data);
    root->left=build_tree();
    root->right=build_tree();
    return root;
}

int count(node *root)
{
    if(root==NULL)
        return 0;

    return 1+ count(root->left) + count(root->right);
}

int sum_of_node(node *root)
{
    if(root==NULL)
        return 0;

    return root->val + sum_of_node(root->left) + sum_of_node(root->right);
}

int main()
{
    node *root=build_tree();
    cout<<endl;
    cout<<count(root);
    cout<<"\nsum of node values \n"<<sum_of_node(root);
}
