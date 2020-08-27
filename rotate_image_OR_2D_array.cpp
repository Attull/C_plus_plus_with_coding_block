#include<iostream>
#include<algorithm>
using namespace std;

void Rotate(int a[][1000],int n)
{
    //Reverse each row one by one
    for(int row=0;row<n;++row)
    {
        int start_col=0;
        int last_col=n-1;

        while(start_col<last_col)
        {
            swap(a[row][start_col],a[row][last_col]);
            start_col++;
            last_col--;
        }
    }

    //Traversing
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            {
                if(i<j)
                    swap(a[i][j],a[j][i]);

            }
    }
}

void rotate_stl(int a[][1000],int n)
{
    //using STL reverse(start_container,end_container) method
    for(int i=0;i<n;++i)
        reverse(a[i],a[i]+n);

    //Traversing
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            {
                if(i<j)
                    swap(a[i][j],a[j][i]);

            }
    }
}
void display(int a[][1000],int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
               cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[1000][1000];
    int n;
    cin>>n;

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>arr[i][j];

   // Rotate(arr,n);
   rotate_stl(arr,n);
    display(arr,n);

    return 0;
}
