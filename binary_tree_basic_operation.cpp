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

    while(data==-1)
    {
        return NULL;
    }

    node *root= new node(data);
    root->left=build_tree();
    root->right=build_tree();
    return root;
}

void print_pre(node *root)
{
    if(root==NULL)
        return ;

    cout<<root->val<<" ";
    print_pre(root->left);
    print_pre(root->right);
}

void print_in(node *root)
{
    if(root==NULL)
        return ;

    print_in(root->left);
    cout<<root->val<<" ";
    print_in(root->right);
}

void print_post(node *root)
{
    if(root==NULL)
        return ;

    print_post(root->left);
    print_post(root->right);
    cout<<root->val<<" ";
}


int main()
{
    node *root=build_tree();
    print_pre(root);
    cout<<endl;
    print_in(root);
    cout<<endl;
    print_post(root);

    return 0;
}

