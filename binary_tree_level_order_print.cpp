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

    node *root=new node(data);
    root->left=build_tree();
    root->right=build_tree();
    return root;
}

void print(node *root)
{
    if(root==NULL)
        return ;

    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int height_of_tree(node *root)
{
    if(root==NULL)
        return 0;

    int ls=height_of_tree(root->left);
    int rs=height_of_tree(root->right);

    return 1+max(ls,rs);                     //1+maximum of left and right subtree
}

void level_order_print(node *root,int k)
{
    if(root==NULL)
        return ;

    if(k==1)
    {
        cout<<root->val<<" ";
        return ;
    }

    level_order_print(root->left,k-1);
    level_order_print(root->right,k-1);
    return;

}

void print_all_kth_level(node *root)
{
    int h=height_of_tree(root);

    for(int i=1;i<=h;++i)
    {
        level_order_print(root,i);
        cout<<endl;
    }
    return;
}
int main()
{
    node *root=build_tree();
    print(root);
    cout<<endl;
    print_all_kth_level(root);
}
