#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class student
{
    public:
    int marks;
    string name;
};

//bucket sort to sort an array of student

void bucket_sort(student s[],int n)
{
    //assuming marks are in range 0-100
    vector<student> v[101];

    for(int i=0;i<n;++i)
    {
        int m=s[i].marks;                         //m store marks of each student one by one
        v[m].push_back(s[i]);                     //and we store object value at position of m i.e if m=24 then we use position 24 to store object student value
    }

    for(int i=100;i>=0;--i)
    {
        for(vector<student>::iterator it=v[i].begin();it!=v[i].end();it++)
            cout<<(*it).marks<<" "<<(*it).name<<endl;
    }

}
int main()
{
    student s[1000];
    int n;
    cin>>n;

    for(int i=0;i<n;++i)
        cin>>s[i].marks>>s[i].name;

    bucket_sort(s,n);

    return 0;
}
