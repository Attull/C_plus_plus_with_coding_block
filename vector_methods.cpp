#include <iostream>
#include <vector>
using namespace std;

int main()
{

   vector <int> a;                    //defining a vector(dynamic array)
   vector <int> d{1,2,3,10,14};

   //push_back/insert at last in O(1)
   d.push_back(20);

   //pop_back//removes the last element o(1)
   d.pop_back();

   //insert some element in the middle
   d.insert(d.begin()+3,100);        //add element 100 after 3rd position
   d.insert(d.begin()+3,4,100);      //after 3rd position add element 100 for four times

   for(int x:d)
   {
       cout<<x<<",";
   }
   cout<<endl;
   //erase some element in the middle
   d.erase(d.begin()+2);             //delete 2nd position element
   d.erase(d.begin()+2,d.begin()+5); //delete range of element

    for(int x:d)
   {
       cout<<x<<",";
   }
   cout<<endl;

   cout<<"Capacity :"<<d.capacity()<<endl;
   cout<<"Size :"<<d.size()<<endl;

   //remove all element of the vector, doesn't delete the memory occupied by memory
    d.clear();

    if(d.empty())
        cout<<"this is empty vector\n";

   d.push_back(10);
   d.push_back(13);
   d.push_back(20);

   cout<<d.front()<<endl;      //print front element
   cout<<d.back()<<endl;       //print last element

   //to avoid doubling, we will use reserve function
   int n;
   cin>>n;
   vector <int> v;
   for(int i=0;i<n;++i)
   {
       int no;
       cout<<"enter element :"<<i+1;
       cin>>no;
       v.push_back(no);
       cout<<"Capacity after element "<<i+1 <<":"<<v.capacity()<<endl;
   }

   for(int x:d)
   {
       cout<<x<<",";
   }
   cout<<endl;

    return 0;
}
