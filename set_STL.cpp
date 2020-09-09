//Sets are a type of associative containers in which each element has to be unique
//element cannot be modified once it is added to the set, though it is possible to remove and add the modified element

#include<iostream>
#include<set>
using namespace std;

int main()
{
    int arr[]={2,3,1,4,5,2,7};
    int n=sizeof(arr)/sizeof(int);

    set<int> s;
    for(int i=0;i<n;++i)
        s.insert(arr[i]);

    //delete
    s.erase(7);
    auto it=s.find(1);
    s.erase(it);

    //print
    for(set<int> :: iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*(it)<<",";
    }

    return 0;
}
