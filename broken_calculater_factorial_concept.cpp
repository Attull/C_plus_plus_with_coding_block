#include<iostream>
using namespace std;

int multiply(int x,int arr[],int ar_size)
{
    int carry=0;                            //carry is used to store carry part e.g in 24 carry store 2
    for(int i=0;i<ar_size;++i)
    {
        arr[i]=arr[i]*x;
        arr[i]=arr[i]+carry;
        carry=arr[i]/10;                   //find carry part if no. contain more than 1 digit
        arr[i]=arr[i]%10;                  //store unit place first i.e in 24 we store 4 at arr[0]
    }

    while(carry)                           //this loop is to store carry part at its correct position e.g in 24 ,carry become 2
    {
        arr[ar_size]=carry%10;
        carry=carry/10;
        ar_size++;                        //after storing carry part in array , size of array increase
    }
    return ar_size;
}

void fact(int n)
{
    int arr[10000]={0};
    arr[0]=1;
    int ar_size=1;                           //to track of length e.g 3!=6 ,its length is 1 4!=24 its length is 2

    for(int i=2;i<=n;++i)                    //e.g 4! which is equal to 24
    {
        ar_size=multiply(i,arr,ar_size);      //here we get ar_size =2 ,contain  2,4 as its element
    }

    for(int i=ar_size-1;i>=0;i--)
    {
        cout<<arr[i];
    }
}
int main()
{
    int n;
    cin>>n;
    fact(n);
    return 0;
}
