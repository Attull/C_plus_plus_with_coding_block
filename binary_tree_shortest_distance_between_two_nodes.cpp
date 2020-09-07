
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
node *lcs(node *root,int a,int b)
{
    if(root==NULL)
        return NULL;

    if(root->val==a || root->val==b)
        return root;

    node *left_ans=lcs(root->left,a,b);
    node *right_ans=lcs(root->left,a,b);

    if(left_ans!=NULL && right_ans!=NULL)
        return root;

    if(left_ans!=NULL)
        return left_ans;

    return right_ans;
}

int find_level(node *root,int a,int level)    //level is just a distance of number from given node
{
    if(root==NULL)
        return -1;

    if(root->val==a)                         //if we find the required value then return value of level
        return level;

    int lf=find_level(root->left,a,level+1);  //just check in left subtree with increasing level by 1

    if(lf!=-1)                               //it means number is present in left subtree
        return lf;                         //so return value of level which is store in lf

    return find_level(root->right,a,level+1);

}

int find_shortest_distance(node *root,int a,int b)
{
    node *lcs_node=lcs(root,a,b);             //we first find lca of both given number and from that we find their distance

    int l1=find_level(lcs_node,a,0);          //give the distance b/w lcs node and a
    int l2=find_level(lcs_node,b,0);          //give the distance b/w lcs node and b

    return l1+l2;
}

int main()
{
    node *root=build_tree();

    int a,b;
    cin>>a>>b;
    cout<<find_shortest_distance(root,a,b);
    return 0;
}
