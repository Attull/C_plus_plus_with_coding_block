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

node* build_tree_from_array(int arr[],int s,int e)
{
    if(s>e)
        return NULL;

    int mid=(s+e)/2;
    node *root=new node(arr[mid]);
    root->left=build_tree_from_array(arr,s,mid-1);
    root->right=build_tree_from_array(arr,mid+1,e);

    return root;
}

void BFS_traversal(node *root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())             //4 2 6 1 3 5 7
    {
        node *f=q.front();
        cout<<f->val<<" ";
        q.pop();

        if(f->left)
            q.push(f->left);

        if(f->right)
            q.push(f->right);
    }
    return ;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int arr[100];
		for(int i=0;i<n;++i)
			cin>>arr[i];

		node* root=build_tree_from_array(arr,0,n-1);
		BFS_traversal(root);
	}
	return 0;
}
