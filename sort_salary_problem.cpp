//Arrange the list in such a manner that the list is sorted in decreasing order of salary. And if two employees have the same salary, they
//should be arranged in lexicographical manner such that the list contains only names of those employees having salary greater than or
//equal to a given number x.
/*
Sample Input
79
4
Eve 78
Bob 99
Suzy 86
Alice 86

Sample Output
Bob 99
Alice 86
Suzy 86

*/
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
bool compare(pair<string,int> a, pair<string,int> b)
{
    if(a.second== b.second)
        return a.first < b.first;

    return a.second >b.second;
}

int main()
{
    int min_sal;
    cin>>min_sal;

    int n;
    cin>>n;

    pair<string, int> s[100];
    int sal;
    string name;

    for(int i=0;i<n;++i)
    {
        cin>>name;
        cin>>sal;
        s[i].first=name;
        s[i].second=sal;
    }

    sort(s,s+n,compare);

    for(int i=0;i<n;++i)
    {
        if(s[i].second>=min_sal)
            cout<<s[i].first<<" "<<s[i].second<<endl;

    }
    return 0;
}
