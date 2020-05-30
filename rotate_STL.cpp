#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);

    cout<<"before rotation \n";
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";

    rotate(arr,arr+2,arr+n);           //2 element move left side from beg i.e rotated from 2nd element

    cout<<"\nafter rotation \n";
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";

    cout<<endl;

    //rotate implementaton in vector

    vector<int> v{1,2,3,4,5,6};

    rotate(v.begin(),v.begin()+3,v.end());

    for(int x:v)
    {
        cout<<x<<" ";
    }

    //next permutation

    cout<<endl;
    vector<int> vv{1,2,3};
    next_permutation(vv.begin(),vv.end());        //it will give next possible permutation i.e for given 123 we get 132 if repeat we get 213

    for(int i=0;i<vv.size();++i)
        cout<<vv[i];


}
