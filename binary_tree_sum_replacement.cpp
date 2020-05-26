
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

int sum_replace(node *root)                            //each node is replace with its child node sums including itself
{
    if(root==NULL)
        return 0;

    if(root->left==NULL && root->right==NULL)
        return root->val;

    int left_sum=sum_replace(root->left);
    int right_sum=sum_replace(root->right);

    int temp=root->val;

    root->val=left_sum + right_sum;

    return temp + root->val;
}

void print(node *root)
{
    if(root==NULL)
        return ;

    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    node *root=build_tree();
    print(root);
    sum_replace(root);
    cout<<endl;
    print(root);
}
