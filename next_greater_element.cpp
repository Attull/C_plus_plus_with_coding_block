/*Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater
  element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1. */

#include <bits/stdc++.h>
using namespace std;

void nextGreater(int arr[], int n)
{
 // Write Code here
 for(int i=0;i<n;++i)
 {
    int next;
    for(int j=i+1;j<n;++j)
    {
        next=-1;
        if(arr[i]<arr[j])
        {
            next=arr[j];
            break;
        }
    }
    cout<<arr[i]<<","<<next<<endl;
 }
}

// The Main Function
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        nextGreater(arr, n);
    }

	return 0;
}

