#include <iostream>
using namespace std;
bool check_sort(int *a,int n)
{
    if(n==1)
        return true;
    else
    {
        if(a[0]<a[1] && check_sort(a+1,n-1))
            return true;
    }
    return false;
}
int main() {

    int a[]={1,2,5,94,5};
    int n=5;
    if(check_sort(a,n))
        cout<<"array is sorted\n";
    else
        cout<<"array is not sorted";
}
