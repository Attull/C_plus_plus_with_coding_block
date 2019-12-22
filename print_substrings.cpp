#include <iostream>
#include<cstring>
using namespace std;

void substring(char *arr)
{
    for(int i=0;arr[i]!='\0';++i)
        for(int j=i;arr[j]!='\0';++j)     //for value of i ,j will start from i and go till end
        {
            for(int k=i;k<=j;++k)
                cout<<arr[k];

            cout<<endl;
        }
}
int main()
{
    char arr[]="atul";
    substring(arr);

}
