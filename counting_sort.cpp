#include<iostream>
#include<algorithm>
using namespace std;

void counting_sort(int a[],int n)
{
    int largest=-1;
    for(int i=0;i<n;++i)                        //finding largest element of array
        largest=max(largest,a[i]);



    int *freq=new int [largest +1]{0};         //array to store frequency of numbers , it can also be define as int freq[largest+1]={0}

    for(int i=0;i<n;++i)
        freq[a[i]]++;                          //store freq of each element when it encountered

    cout<<endl;
    for(int i=1;i<=largest;++i)
    {
        int p=freq[i];                         //storing frequency of each element one by one
        while(p--)                             //print it till its freq become 0
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int a[]={2,4,1,4,5,2,2};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<"counting sort \n";
    counting_sort(a,n);

    return 0;
}
