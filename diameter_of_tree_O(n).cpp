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

class Pair
{
    public:
            int diameter;
            int height;
};

Pair fast_diameter(node *root)
{
    Pair p;
    if(root==NULL)
    {
        p.diameter=p.height=0;
        return p;
    }

    Pair left=fast_diameter(root->left);
    Pair right=fast_diameter(root->right);

    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));

    return p;
}

int main()
{
    node *root=build_tree();
    Pair p=fast_diameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;

    return 0;
}
