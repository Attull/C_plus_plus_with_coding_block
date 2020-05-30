#include<iostream>
#include<algorithm>             //for binary_search(),lower_bound(), upper_bound();
using namespace std;

int main()
{
    int arr[]={2,5,7,7,12,90};
    int n=sizeof(arr)/sizeof(int);

    int key;
    cout<<"enter element to search \n";
    cin>>key;

    bool i=binary_search(arr,arr+n,key);         //it return true and false
    if(i)
        cout<<"element is found\n";
    else
        cout<<"element is not found\n";

    auto lb=lower_bound(arr,arr+n,7);            //first element greater than equal to key i.e 7
    cout<<"lower bound of 7 is "<<lb-arr;        //give position

    auto ub=upper_bound(arr,arr+n,7);            //first element strictly greater than key i.e 7
    cout<<"\nupper bound of 7 is "<<ub-arr;

    if((ub-arr)==n)
        cout<<"\nelement is not present ";


    return 0;
}
