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

node *insert_in_bst(node *root,int data)
{
    node *temp=new node(data);

    //base case
    if(root==NULL)
        return temp;

    //rec case
    if(data<=root->val)                                      //if data is less then current root value then insert it in left subtree
        root->left=insert_in_bst(root->left,data);
    else
        root->right=insert_in_bst(root->right,data);

}

void bfs(node *root)                    //using queue
{
        queue <node*> q;
        q.push(root);                              //first push node
        q.push(NULL);                              //then push NULL

        while(!q.empty())
        {
            node *f=q.front();
            if(f==NULL)                            //if NULL encounter
            {
                cout<<endl;                       //move to next line
                q.pop();                          //remove NULL from queue
                if(!q.empty())
                {                                 //if queue is not empty then push NULL in queue i.e.
                    q.push(NULL);                 // if queue is 6,7 then it become 6,7,NULL
                }
            }
            else                                  //if element is encounter
             {
                cout<<f->val<<",";               //print it
                q.pop();                         //then pop it

                if(f->left)                      //if it has left child then push it in queue
                {
                    q.push(f->left);
                }
                if(f->right)                     //if it has right child then push it in queue
                {
                    q.push(f->right);
                }
             }
        }
        return ;
}
node *build()
{
    int d;
    cin>>d;

    node *root=NULL;

    while(d!=-1)
    {
        root=insert_in_bst(root,d);
        cin>>d;
    }

    return root;
}

bool search_in_bst(node *root,int data)
{
    if(root==NULL)
        return false;

    if(root->val==data)
        return true;

    if(root->val>=data)
        search_in_bst(root->left,data);
    else
        search_in_bst(root->right,data);

}

node *delete_in_bst(node *root,int data)
{
   if(root==NULL)
   {
       return NULL;
   }
   else if(data<root->val)
   {
       root->left=delete_in_bst(root->left,data);
       return root;
   }
   else if(data==root->val)
   {
       //node can be present in three possible way and to delete each of them we use different approach
        //1. Node with 0 children -leaf node
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //2. Node with only one child
        if(root->left!=NULL && root->right==NULL)
        {
            node *temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            node *temp=root->right;
            delete root;
            return temp;
        }
        //3.Node with two child
        node *replce=root->right;                     //to find inorder successor(smallest element) from right
        while(replce->left!=NULL)
        {
            replce=replce->left;
        }
        root->val=replce->val;                       //after find inorder successor replace root value with it
        root->right=delete_in_bst(root->right,replce->val);      //then call delete function to delete it
        return root;
   }
   else
   {
       root->right=delete_in_bst(root->right,data);
       return root;
   }
}

void inorder(node *root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    node *root=build();

    bfs(root);
    cout<<endl;

    int s;
    cin>>s;

    root=delete_in_bst(root,s);

    bfs(root);
   // cout<<search_in_bst(root,3);
    return 0;
}
