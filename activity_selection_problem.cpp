#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int>p2)
{
    return p1.second <p2.second;
}

int main()
{
    int t,n,s,e;
    cin>>t;

    vector<pair<int,int>> v;                        //we use pair to store two values start time and end time
    while(t--)
    {
        cin>>n;                                     //number of activity
        for(int i=0;i<n;++i)
        {
            cin>>s>>e;
            v.push_back(make_pair(s,e));           //make_pair() is used to insert values in pair dataset
        }

        sort(v.begin(),v.end(),compare);           //sort as per the end time

        //start picking activities
        int cnt=1;
        int fin=v[0].second;                      //assuming first activity to be done first as we used greedy concept

        //iterate over remaining activities
        for(int i=1;i<n;++i)
        {
            if(v[i].first>=fin)                  //if start time of any other activity is greater the end time of previous activity
            {                                    //then that activity can be performed
                fin=v[i].second;
                ++cnt;
            }
        }
        cout<<cnt;
        v.clear();                    //for each new test case we clear previous vector
  }

}
