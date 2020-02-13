#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int mycompare(string x,string y)
{
    string xy=x.append(y);

    string yx=y.append(x);

    if(xy>yx)
        return 1;
    else
        return 0;
}

int main()
{
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    int num;
    cin>>num;

    string arr[100];

    for(int i=0;i<num;++i)
        cin>>arr[i];

    sort(arr,arr+num,mycompare);

    for(int i=0;i<num;++i)
        cout<<arr[i];

    cout<<endl;
  }

    return 0;
}
