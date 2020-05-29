#include<iostream>
using namespace std;

class treenode
{
    public:
            int val;
            treenode *left;
            treenode *right;

            treenode(int data)
            {
                val=data;
                left=NULL;
                right=NULL;
            }
};

void print_Kdistance_down(treenode* root,int k)
{
    if(root==NULL || k<0)
        return ;

    if(k==0)
    {
        cout<<root->val<<endl;
        return;
    }

    print_Kdistance_down(root->left,k-1);
    print_Kdistance_down(root->right,k-1);
}

int print_Kdistance_ancestor(treenode* root,treenode* target,int k)
{
    if(root==NULL)
        return -1;

    if(root==target)
    {
        print_Kdistance_down(root,k);
        return 0;
    }

    int left_side=print_Kdistance_ancestor(root->left,target,k);

    if(left_side!=-1)
    {
        if(left_side+1==k)
            cout<<root->val<<endl;
        else
        {
            print_Kdistance_down(root->right,k-2-left_side);//  instead of print_Kdistance_ancestor(root->right,target,k-2-left_side);
        }

    return left_side+1;
    }

    int right_side=print_Kdistance_ancestor(root->right,target,k);

    if(right_side!=-1)
    {
        if(right_side+1==k)
            cout<<root->val<<endl;
        else
        {
            print_Kdistance_down(root->left,k-2-right_side);  // instead of print_Kdistance_ancestor(root->left,target,k-2-right_side)
        }

    return right_side+1;
    }

    return -1;
}


treenode *build_tree()
{
    int data;
    cin>>data;

    // while(data==-1)
    // {
    //     return NULL;
    // }
    if(data==-1){
        return NULL;
    }
    treenode *root=new treenode(data);
    root->left=build_tree();
    root->right=build_tree();
    // you did'nt return root
    return root;
}

int main()
{
    treenode *root=build_tree();
    treenode *target=root->left;
    print_Kdistance_ancestor(root,target,2);
    return 0;
}
