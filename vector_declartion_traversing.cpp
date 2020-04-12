// vector=>dynamic array

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // initialise vector
   vector <int> a;                    //defining a vector(dynamic array)
   vector <int> b(5,10);              //five int value with value 10
   vector <int> c(b.begin(),b.end());
   //   vector <int> d{1,2,3,10,14};

   // iterate vector value
   //method 1
    for(int i=0;i<c.size();++i)        //for display
   {
       cout<<c[i]<<",";
   }
   cout<<endl;

   //method 2
   vector<int>::iterator i;
   for( i=b.begin();i!=b.end();++i)
   {
       cout<<(*i)<<",";
   }

/*
   //method 3
   for(int x:c)
   {
       cout<<x<<",";
   }
   cout<<endl;
*/

   int n,temp;
   cout<<"\nenter the number of element \n";
   cin>>n;

   for(int i=0;i<n;++i)               //give input to vector
   {
    cout<<"enter element "<<i+1<<": ";
    cin>>temp;
    a.push_back(temp);                //insert element at the last of vector
   }

   for(int i=0;i<a.size();++i)        //for display
   {
       cout<<a[i]<<" ";
   }

   cout<<"\n"<<a.capacity();          //Return size of allocated storage capacity

    return 0;
}
