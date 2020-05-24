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

int height_of_tree(node *root)
{
    if(root==NULL)
        return 0;

    int ls=height_of_tree(root->left);
    int rs=height_of_tree(root->right);

    return 1+max(ls,rs);                            //1+maximum of left and right subtree
}

void BFS_traversal_2(node *root)                    //using queue
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


int main()
{
    node *root=build_tree();
    cout<<"\nLevel order print using BFS \n";
    BFS_traversal_2(root);
}
