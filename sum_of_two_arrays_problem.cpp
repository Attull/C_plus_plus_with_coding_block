/*
Sample Input
4
1 0 2 9
5
3 4 5 6 7
Sample Output
3, 5, 5, 9, 6, END
*/

#include<iostream>
using namespace std;

void add(int a[],int b[],int n,int m)
{
    int carry=0,sum[n],s=0;

   int i=n-1,j=m-1;
   int k=n-1;

    while(j>=0)                    //j contain value of m so we first calculate the sum for m values from last
    {
        s=a[i]+b[j]+carry;
        sum[i]=s%10;
        carry=s/10;
        i--;
        j--;
        k--;
    }

    while(i>=0)                    //i contain value of n which is greater than m so after adding m elments , we then add remaining elements in sum array
    {
        s=a[i]+carry;
        sum[k]=s%10;
        carry=s/10;
         i--;
         k--;
    }

    if(carry)
        cout<<carry<<", ";

    for(int j=0;j<n;++j)
        cout<<sum[j]<<", ";

    cout<<"END";
}

int main()
{
    int a[10001],b[10001];
    int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    cin>>m;
	for(int i=0;i<m;i++){
		cin>>b[i];
	}

	if(n>=m)
        add(a,b,n,m);
    else
        add(b,a,m,n);

    return 0;
}
