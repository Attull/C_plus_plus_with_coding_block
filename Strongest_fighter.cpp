/*
Problem
-------
There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.

Input Format
------------
First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k

Constraints
-----------
1<=N<=10^5
1<=k<=N
1 <= Ai <= 100000  */

#include<iostream>
using namespace std;

void strong(long long int arr[],long long int n,int sub)
{
	for(int i=0,j=sub;i<=n-sub;++i,++j)
	{
		long long int m=arr[i];
		for(int k=i;k<j;++k)
		{
            if(m<arr[k])
                m=arr[k];
		}
        cout<<m<<" ";
	}
}
int main() {
	long long int n,arr[100000];
	int sub;
	cin>>n;

	for(int i=0;i<n;++i)
		cin>>arr[i];

	cin>>sub;

	strong(arr,n,sub);
	return 0;
}
