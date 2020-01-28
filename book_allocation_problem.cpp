#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long int

bool isvalidconfig(ll books[],ll n,ll stu,ll ans)
{
    int student=1;                                      //student variable to count number of student
    ll cur_pages=0;

    for(int i=0;i<n;++i)
    {
        if(cur_pages+books[i]>ans)                      //if sum of pages is greater than tha mid value
        {
            student++;                                  //take another student
            cur_pages=books[i];
            if(student>stu)                             //if no. of student become greater than given no. of student
                return false;                           //return false
        }
        else
        {
            cur_pages+=books[i];
        }
    }
    return true;
}

ll bap(ll books[],ll n,ll stu)               //bap-bool allocation problem
{
    ll total_pages=0;
    ll s=0,e=0;

    for(int i=0;i<n;++i)
    {
        total_pages+=books[i];                // count total number of pages
        s=max(s,books[i]);
    }

    e=total_pages;                           //assign end variable as total number of pages
    ll final_ans=s;
    while(s<=e)
    {
        ll mid=(s+e)/2;

        if(isvalidconfig(books,n,stu,mid))    //if current mid value is valid configuration
        {
            final_ans=mid;                    //store it in final_ans variable ,later to check whether smaller answer is possible or not
            e=mid-1;
        }
        else
        {
            s=mid+1;                          // if current mid is not valid, then check in right side
        }

    }
    return final_ans;
}

int main()
{
    ll n,stu;
    ll books[10005];
    cout<<"enter number of books \n";
    cin>>n;

    cout<<"number of student \n";
    cin>>stu;

    cout<<"enter number of pages of books \n";
    for(int i=0;i<n;++i)
        cin>>books[i];

    cout<<bap(books,n,stu)<<endl;
    return 0;
}
