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


int diameter(node *root)                         //time complexity for finding height O(n)
{                                                //in this we find height for each node so,
    if(root==NULL)                                //time complexity here for finding diameter is O(n^2)
        return 0;

    int h1=diameter(root->left);
    int h2=diameter(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);

    return max(op1,max(op2,op3));
}
int main()
{
    node *root=build_tree();
    cout<<diameter(root);
}
