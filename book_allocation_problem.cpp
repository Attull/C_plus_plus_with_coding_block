#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long int

bool isvalidconfig(ll books[],ll nb,ll stu,ll ans)
{
    int student=1;                                      //student variable to count number of student
    ll pages_reading=0;

    for(int i=0;i<nb;++i)
    {
        if(pages_reading+books[i]>ans)                      //if sum of pages is greater than the mid value
        {
            student++;                                  //take another student
            pages_reading=books[i];
            if(student>stu)                             //if no. of student become greater than given no. of student
                return false;                           //return false
        }
        else
        {
            pages_reading+=books[i];
        }
    }
    return true;
}

ll bap(ll books[],ll nb,ll stu)               //bap-bool allocation problem
{
    ll total_pages=0;
    ll s=0,e=0;

    for(int i=0;i<nb;++i)
    {
        total_pages+=books[i];                // count total number of pages
        s=max(s,books[i]);
    }

    e=total_pages;                           //assign end variable as total number of pages
    ll final_ans=s;
    while(s<=e)
    {
        ll mid=(s+e)/2;

        if(isvalidconfig(books,nb,stu,mid))    //if current mid value is valid configuration i.e no student is read more than mid number of pages
        {
            final_ans=mid;                    //store it in final_ans variable ,later to check whether smaller answer is possible or not
               e=mid-1;
        }
        else
        {
            //it is not possible to divide the current mid number of pages ,so we increase the mid value by changing value of 's'
            s=mid+1;                          // if current mid is not valid, then check in right side
        }

    }
    return final_ans;
}

int main()
{
    ll nb,stu;
    ll books[10005];
    cout<<"enter number of books \n";
    cin>>nb;

    cout<<"number of student \n";
    cin>>stu;

    cout<<"enter number of pages of books \n";
    for(int i=0;i<nb;++i)
        cin>>books[i];

    cout<<bap(books,nb,stu)<<endl;
    return 0;
}
