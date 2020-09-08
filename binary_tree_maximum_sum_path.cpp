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

class Pair
{
    public:
            int branch_sum;            //starting from root to other branch
            int max_sum;               //maximum sum by including or excluding left and right subtree sum

            Pair()
            {
                branch_sum=0;
                max_sum=0;
            }
};

Pair max_sum(node *root)
{
    Pair p;

    //base case
    if(root==NULL)
        return p;

    Pair left=max_sum(root->left);
    Pair right=max_sum(root->right);

    //including root val with all possible case for max sum
    int opt1=root->val;
    int opt2=root->val +left.branch_sum;
    int opt3=root->val +right.branch_sum;
    int opt4=root->val +left.branch_sum +right.branch_sum;

    int cur_ans_through_root=max(opt1,max(opt2,max(opt3,opt4)));

    //branch sum for current root
    p.branch_sum=max(left.branch_sum,max(right.branch_sum,0)) + root->val;        //0 is to handle negative answer case

    p.max_sum=max(left.max_sum,max(right.max_sum,cur_ans_through_root));

    return p;
}

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


int main()
{
    node *root=build_tree();

    Pair temp=max_sum(root);

    cout<<temp.max_sum;
}
