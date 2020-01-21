#include<iostream>
#include<algorithm>
using namespace std;

int binary_srch(int a[],int num,int beg,int last)
{
    int mid,ans=-1;

    while(beg<=last)
    {
        mid=(beg+last)/2;

        if(a[mid]==num)
            return mid;

      //check if left array is sorted or not
        if(a[beg]<=a[mid])
        {
            if(a[beg]<=num && num<=a[mid])             //if sorted then check the element b/w beg & mid
            {
                return binary_srch(a,num,beg,mid-1);
            }
            else
            {
                return binary_srch(a,num,mid+1,last);
            }
        }
        //check if right array is sorted or not
        if(a[last]>=a[mid])
        {
            if(a[mid]<=num && num<=a[last])
            {
                return binary_srch(a,num,mid+1,last);
            }
            else
            {
                return binary_srch(a,num,beg,mid-1);
            }
        }
    }
    return ans;

}

int main()
{
    int a[]={4,5,1,2,3};
    int n=sizeof(a)/sizeof(a[0]);

    int num;
    cout<<"enter element to search \n";
    cin>>num;

    int index=binary_srch(a,num,0,n-1);

    if(index<0)
        cout<<"not found\n";
    else
        cout<<"found at index "<<index;

    return 0;
}
