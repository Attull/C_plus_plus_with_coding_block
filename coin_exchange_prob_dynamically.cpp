#include<iostream>
using namespace std;

int count(int *arr,int m,int sum)
{
	int sol[m+1][sum+1];               //define a 2D matrix to store values

	for(int i=0;i<m+1;++i)             //make all element of first column is 1 bcoz for sum=0,there is always exist solution
 		sol[i][0]=1;


	for(int i=1;i<=sum;++i)            //make elements of first row =0
		sol[0][i]=0;

	for(int i=1;i<m+1;++i)
	{
		for(int j=1;j<=sum;++j)
		{
		    if(arr[i-1]<=j)                                   //if coin denomination value is less than or equal to required sum value
				sol[i][j]=sol[i-1][j]+sol[i][j-arr[i-1]];
			else
				sol[i][j]=sol[i-1][j];

		}
	}

	cout<<"Table \n";

    for(int i=0;i<m+1;++i)
	{
		for(int j=0;j<=sum;++j)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }


    return sol[m][sum];               //our answer is last element of sol table
}


int main()
{
	int sum;
	cin>>sum;

	int arr[]={3,5,10};
	cout<<endl<<"Minimum coin required is :"<<count(arr,3,sum);
	return 0;
}
