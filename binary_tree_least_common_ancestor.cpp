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

node* build_tree()
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

node *lca(node *root,int a,int b)
{
    if(root==NULL)
        return NULL;

    if(root->val==a || root->val==b)
        return root;

    //search in left and right subtree
    node *left_ans=lca(root->left,a,b);
    node *right_ans=lca(root->right,a,b);

    if(left_ans!=NULL && right_ans!=NULL)     //it means both a and is present on either side of root
        return root;

    if(left_ans!=NULL)                       //it means we get one a or b in left side so if return that node
    {
        return left_ans;
    }
    return right_ans;

}

int main()
{
    node *root=build_tree();

    int a,b;
    cin>>a>>b;

    cout<<"lca of "<<a<<" & "<<b<<" is :";
    node *ans=lca(root,a,b);

    cout<<ans->val;

    return 0;
}
