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
        print_Kdistance_down(root,k);                              // if target is found then first found all node at distance k in downward
        return 0;
    }

    int left_side_dist=print_Kdistance_ancestor(root->left,target,k);  //give left distance of target node from root

    if(left_side_dist!=-1)
    {
        if(left_side_dist+1==k)            //it means value present at one of root
            cout<<root->val<<endl;
        else
        {
            print_Kdistance_down(root->right,k-2-left_side_dist);     // if it is not at root then it van be present at right subtree
        }
    return left_side_dist+1;              //return left distance to above root node
    }

    int right_side_dist=print_Kdistance_ancestor(root->right,target,k); //give right distance of target node from root

    if(right_side_dist!=-1)
    {
        if(right_side_dist+1==k)
            cout<<root->val<<endl;
        else
        {
            print_Kdistance_down(root->left,k-2-right_side_dist);
        }

    return right_side_dist+1;
    }

    return -1;
}


treenode *build_tree()
{
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    treenode *root=new treenode(data);
    root->left=build_tree();
    root->right=build_tree();

    return root;
}

int main()
{
    treenode *root=build_tree();

    treenode *target=root->right;

    print_Kdistance_ancestor(root,target,2);
    return 0;
}
