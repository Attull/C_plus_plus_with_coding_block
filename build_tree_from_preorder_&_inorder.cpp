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

node *create_tree(int ino[],int preo[],int s,int e)
{
    static int i=0;                            //static bcoz we didn't want to make value of i=0 again or we can use it as global variable

    //base case
    if(s>e)
        return NULL;

    //rec case

    node *root=new node(preo[i]);             //first make node with first value of pre0[] array which is root node of tree
    int index=-1;
    for(int j=s;j<=e;++j)
    {
        if(ino[j]==preo[i])                  //search in ino[] array and store its index
        {
            index=j;
            break;
        }
    }

    i++;
    root->left=create_tree(ino,preo,s,index-1);
    root->right=create_tree(ino,preo,index+1,e);

    return root;
}

void print(node *root)
{
    if(root==NULL)
        return;

    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
int main()
{
    int ino[]={3,2,8,4,1,6,7,5};
    int preo[]={1,2,3,4,8,5,6,7};

    int n=sizeof(ino)/sizeof(int);
    node *root=create_tree(ino,preo,0,n-1);
    print(root);
    return 0;
}
