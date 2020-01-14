#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
   vector <int> a;                    //defining a vector(dynamic array)
   a.reserve(1);                      //specify the minimum size of the vector

   int n,temp;
   cout<<"enter the number of element \n";
   cin>>n;

   for(int i=0;i<n;++i)               //give input to vector
   {
    cout<<"enter element "<<i+1<<": ";
    cin>>temp;
    a.push_back(temp);                //insert element in starting
   }

   a.pop_back();                      //delete element from last

   sort(a.begin(),a.end());           //sort() function work similiar as in array

   for(int i=0;i<a.size();++i)        //for display
   {
       cout<<a[i]<<" ";
   }
   cout<<"\n"<<a.capacity();          //Return size of allocated storage capacity
}
