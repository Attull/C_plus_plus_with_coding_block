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

treenode *build_tree()
{
    int data;
    cin>>data;

    while(data==-1)
    {
        return NULL;
    }
    treenode *root=new treenode(data);
    root->left=build_tree();
    root->right=build_tree();
}

void rview(treenode *root,int level,int *maxlevel)
{
    if(root==NULL)
        return;

    if(*maxlevel<level)
    {
        *maxlevel=level;
        cout<<root->val<<" ";
    }

    rview(root->right,level+1,maxlevel);
    rview(root->left,level+1,maxlevel);
}

void right_view(treenode *root)
{
    int maxlevel=-1;
    rview(root,1,&maxlevel);
}
int main()
{
    treenode *root=build_tree();
    right_view(root);
    return 0;
}
