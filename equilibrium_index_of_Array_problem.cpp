//Given an array, find the equilibrium index of an array. Equilibrium index is an index such that the sum of elements at lower indexes
// is equal to the sum of elements at higher indexes. If no Equilibrium index exists Display -1.

/*
input
7
-6 2 5 2 -4 4 1

output
3
*/
#include<iostream>
using namespace std;

int find_sum(int *arr,int n,int s,int e)
{
	int sum=0;
	for(int j=s;j<=e;++j)
	{
		sum+=arr[j];
	}
	return sum;
}
int eqi_index(int *arr,int n)
{
	for(int i=0;i<n;++i)
	{
		int left_sum=find_sum(arr,i,0,i-1);
		cout<<"left subarray sum for index "<<i<<" is "<<left_sum<<endl;
		int right_sum=find_sum(arr,n-i,i+1,n-1);
		cout<<"right subarray sum for index "<<i<<" is "<<right_sum<<endl;

		if(left_sum==right_sum)
			return i;
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;

	int arr[1001]={0};

	for(int i=0;i<n;++i)
		cin>>arr[i];

	int index=eqi_index(arr,n);

	cout<<index;
	return 0;
}
